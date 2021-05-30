//
// Created by juanpr on 29/5/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_PLAYER_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_PLAYER_H


class Player {
    int ID = 0;
public:
    int getId() const;

    void setId(int id);

    int getTeam() const;

    void setTeam(int team);

    int getPosX() const;

    void setPosX(int posX);

    int getPosY() const;

    void setPosY(int posY);

private:
    int team = 0;
    int posX = 0;
    int posY = 0;

};


#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_PLAYER_H
