#include "PathFinding.h"

PathFinding::PathFinding(void)
{
    m_initializeStartGoal = false;
    m_foundGoal = false;
}
PathFinding::~PathFinding(void)
{
}
void PathFinding::FindPath(Vector3 currentPos, Vector targetPos)
{
    if(!m_initializeStartGoal)//Sees if the a* has began
    {//Clear the lists for the use of the a*
        for(int i = 0; i < m_openList.size(); i++)
        {
            delete m_openList[i];
        }
        m_openList.clear();

        for(int i = 0; i < m_visitedList.size(); i++)
        {
            delete m_visitedList[i];
        }
        m_visitedList.clear();

        for(int i = 0; m_pathToGoal.size(); i++)
        {
            delete m_pathToGoal[i];
        }
        m_pathToGoal.clear();

        //Initialize start
        SearchCell start;
        start.m_xcoord = currentPos.x;
        start.m_zcoord = currentPos.y;

        //Initialize goal
        SeachCell goal;
        goal.m_xcoord = targetPos.x;
        goal.m_zcoord = targetPos.y;

        SetStartAndGoal(start, goal);
        m_initializeStartGoal = true;
    }
    if (m_initializeStartGoal)
    {
        ContinuePath();
    }
}
void PathFinding::SetStartAndGoal(SearchCell start, SearchCell goal)
{
    m_startCell = new SearchCell(start.m_xcoord, start.m_zcoord, NULL);
    m_goalCell = new SearchCell(goal.m_xcoord, goal.m_zcoord, &goal);

    m_startCell->G = 0;
    m_startCell->H = m_startCell->ManHattanDistance(m_goalCell);
    m_startCell->parent = 0;

    m_openList.push_back(m_startCell);
}
SearchCell *PathFinding::GetNextCell()
{
    float  bestF = 99999.Of;//
    int cellIndex = -1;
    SearchCell *nextCell = NULL;

    for (int i = 0; i < m_openList.size(); ++i)//Calculate the best route
    {
        if(m_openList[i]->GetF() < bestF)
        {
            bestF = m_openList[i]->GetF();
            cellIndex = i;
        }
    }

    if (cellIndex >= 0)
    {
        nextCell = m_openList[cellIndex];
        m_visitedList.push_back(nextCell);
        m_openList.erase(m_openList.begin() + cellIndex);
    }

    return nextCell;
}
void PathFinding::PathOpened(int x, int z, float newCost, SearchCell *parent)
{
    if(Cell_Blocked)//Sees if the next cell if available
    {
        return;
    }

    int id = z * World_size + x;
    for (int i = 0; i < m_visitedList.size(); ++i)
    {
        if(id == m_visitedList[i]->m_id)//Sees if the cell is in the world
        {
            return;
        }
    }

    SearchCell *newChild = new SearchCell(x, z, parent);
    newChild->G = newCost;
    newChild->H = parent->ManHattanDistance(m_goalCell);

    for (int m = 0; m < m_openList.size(); ++m)
    {
        if(id == m_openList[i]->m_id)
        {
            float newF = newChild->G + newCost + m_openList[i]->H;

            if(m_openList[i]->GetF() > newF)
            {
                m_openList[i]->G = newChild->G + newCost;
                m_openList[i]->parent = newChild;
            }else
            {
                delete newChild;
                return;
            }
        }
    }
    m_openList.push_back(newChild);
}
void PathFinding::ContinuePath()
{
    if(m_openList.empty())
    {
        return;
    }

    SearchCell *currentCell = GetNextCell();

    if(currentCell->m_id == m_goalCell->m_id)//Checks if the current cell is the goal
    {
        m_goalCell->parent = currentCell->parent;

        SearchCell *getPath;

        for (getPath = m_goalCell; getPath != NULL; getPath = getPath->parent)
        {
            m_pathToGoal.push_back(new Vector3(getPath->m_xcoord, 0, getPath->m_zcoord));
        }

        m_foundGoal = true;
        return;
    } else//Checks the adjacent cells
    {
        //right Side
        PathOpened(currentCell->m_xcoord + 1, currentCell->m_zcoord, currentCell->G + 1, currentCell);
        //left Side
        PathOpened(currentCell->m_xcoord - 1, currentCell->m_zcoord, currentCell->G + 1, currentCell);
        //Up
        PathOpened(currentCell->m_xcoord , currentCell->m_zcoord + 1, currentCell->G + 1, currentCell);
        //Down
        PathOpened(currentCell->m_xcoord , currentCell->m_zcoord - 1, currentCell->G + 1, currentCell);
        //left-up Diagonal
        PathOpened(currentCell->m_xcoord - 1, currentCell->m_zcoord + 1, currentCell->G + 1.414f, currentCell);
        //right-up Diagonal
        PathOpened(currentCell->m_xcoord + 1, currentCell->m_zcoord + 1, currentCell->G + 1.414f, currentCell);
        //left-down Diagonal
        PathOpened(currentCell->m_xcoord - 1, currentCell->m_zcoord - 1, currentCell->G + 1.414f, currentCell);
        //right-down Diagonal
        PathOpened(currentCell->m_xcoord + 1, currentCell->m_zcoord - 1, currentCell->G + 1.414f, currentCell);

        for(int i = 0; i < m_openList.size(); i++)
        {
            m_openList.erase(m_openList.begin() + i);
        }
    }
}
Vector3 PathFinding::NextPathPos()//
{
    int index = 1;

    Vector3 nextPos;

    nextPos.x = m_pathToGoal[m_pathToGoal.size() - index].x;
    nextPos.z = m_pathToGoal[m_pathToGoal.size() - index].z;

    Vector3 distance = nextPos - pos;//Calculates the game object position

    if (index < m_pathToGoal.size())
    {
        if (distance.Length() < radius)//Sees if the game object enters the cell
        {
            m_pathToGoal.erase(m_pathToGoal.end() - index);
        }
    }

    return nextPos;
}