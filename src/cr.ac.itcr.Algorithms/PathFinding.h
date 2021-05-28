#include <iostream>
#include "Vector3.h"
#include <vector>
#include "SeachCell.h"

class PathFinding
{
public:
    PathFinding(void);
    ~PathFinding(void);

    void FindPath (Vector3 currentPos, Vector3 targetPos);
    Vector3 NextPathPos();
    void ClearOpenList(){ m_openList.clear();}
    void ClearVisitedList(){ m_visitedList.clear();}
    void ClearPathGoal(){ m.pathToGoal.clear();}
    bool m_initializeStartGoal;
    bool m_foundGoal;

private:
    void SetStartAndGoal(SeachCell start, SeachCell goal);
    void PathOpened (int x, int z, float newCost, SeachCell *parent);
    SeachCell *GetNextCell();
    void ContinuePath ();

    SearchCell *m_startCell;
    SearchCell *m_goalCell;
    std::vector<SearchCell*> m_openList;
    std::vector<SearchCell*> m_visitedList;
    std::vector<SearchCell*> m_pathToGoal;
};