//
// Created by juanpr on 29/5/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_PLAYER_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_PLAYER_H


class Player {
    /**
     * @class Represents a player object that can shoot a ball
     * with a given force and direction
     */
public:
    /**
     * @brief getter for the player's ID
     * @return id integer attribute
     */
    int getId() const;
    /**
        * @brief setter for the player's ID
        *
        */
    void setId(int id);
    /**
        * @brief getter for the player's team
        * @return team integer attribute
        */
    int getTeam() const;
    /**
        * @brief setter for the player's team
        *
        */
    void setTeam(int team);
    /**
        * @brief getter for the player's x axis position
        * @return posX integer attribute
        */
    int getPosX() const;
    /**
        * @brief setter for the player's X axis position
        *
        */
    void setPosX(int posX);
    /**
        * @brief getter for the player's y axis position
        * @return posY integer attribute
        */
    int getPosY() const;
/**
        * @brief setter for the player's Y axis position
        *
        */
    void setPosY(int posY);

private:
    int team = 0;
    int posX = 0;
    int posY = 0;
    int ID = 0;

};


#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_PLAYER_H
