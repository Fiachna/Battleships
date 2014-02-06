#include "graphical.h"
#include <iostream>

using namespace std;

namespace Battleships
{
//----------------------------------------------------------------------------------------------------------//
    void Graphical::init_Interface()
    {
        window = initwindow(1024, 768, "Is this Battletoads?");
        setbkcolor(BLACK);

        string leftBoard, rightBoard;
        int leftTextX, rightTextX, boardTextY;

        leftBoard = "Current Player Board";
        rightBoard = "Opponent Board";

        settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);

        leftTextX = (512 - textwidth(leftBoard.c_str())) / 2;
        rightTextX = (512 - textwidth(rightBoard.c_str())) / 2 + 512;
        boardTextY = 550;

        setfillstyle(SOLID_FILL, BLUE);
        bar(0, boardTextY, 1023, boardTextY + textheight(leftBoard.c_str()));
        outtextxy(leftTextX, boardTextY, leftBoard.c_str());
        outtextxy(rightTextX, boardTextY, rightBoard.c_str());
    }
//----------------------------------------------------------------------------------------------------------//
    void Graphical::uninit_Interface()
    {
        closegraph();
    }
//----------------------------------------------------------------------------------------------------------//
    void Graphical::showMyBoard(Board boardToShow)
    {
        unsigned row, column, numRows, numColumns;
        unsigned left, right, top, bottom;
        unsigned borderX, borderY;
        Cell* tempCell;

        numRows = boardToShow.getBoardRows();
        numColumns = boardToShow.getBoardColumns();
        borderX = 56 + (20 - numColumns)*10;
        borderY = 124 + (20 - numRows)*10;

        for(row=0; row<numRows; row++)
        {
            for(column=0; column<numColumns; column++)
            {
                tempCell = boardToShow.getCellByLocation(row, column);
                switch(tempCell->getCellState())
                {
                    case Cell::HIT:
                    {
                        setfillstyle(SOLID_FILL, RED);
                        break;
                    }
                    case Cell::MISS:
                    {
                        setfillstyle(SOLID_FILL, WHITE);
                        break;
                    }
                    case Cell::UNKNOWN:
                    default:
                    {
                        setfillstyle(SOLID_FILL, BLUE);
                        break;
                    }
                }
                left = borderX + 20 * column + 1;
                right = borderX + 20 * (column + 1);
                top = borderY + 20 * row + 1;
                bottom = borderY + 20 * (row + 1);
                bar3d(left, top, right, bottom, 0, 1);
            }
        }
    }
//----------------------------------------------------------------------------------------------------------//
    void Graphical::showOpponentBoard(Board boardToShow)
    {
        unsigned row, column, numRows, numColumns;
        unsigned left, right, top, bottom;
        unsigned borderX, borderY;
        Cell* tempCell;

        numRows = boardToShow.getBoardRows();
        numColumns = boardToShow.getBoardColumns();
        borderX = 568 + (20 - numColumns)*10;
        borderY = 124 + (20 - numRows)*10;

        for(row=0; row<numRows; row++)
        {
            for(column=0; column<numColumns; column++)
            {
                tempCell = boardToShow.getCellByLocation(row, column);
                switch(tempCell->getCellState())
                {
                    case Cell::HIT:
                    {
                        setfillstyle(SOLID_FILL, RED);
                        break;
                    }
                    case Cell::MISS:
                    {
                        setfillstyle(SOLID_FILL, WHITE);
                        break;
                    }
                    case Cell::UNKNOWN:
                    default:
                    {
                        setfillstyle(SOLID_FILL, BLUE);
                        break;
                    }
                }
                left = borderX + 20 * column + 1;
                right = borderX + 20 * (column + 1);
                top = borderY + 20 * row + 1;
                bottom = borderY + 20 * (row + 1);
                bar3d(left, top, right, bottom, 0, 1);
            }
        }
    }
//----------------------------------------------------------------------------------------------------------//
    void Graphical::showFleet(Board boardWithFleet)
    {
        unsigned row, column, numRows, numColumns;
        unsigned left, right, top, bottom;
        unsigned borderX, borderY;
        Cell* tempCell;

        numRows = boardWithFleet.getBoardRows();
        numColumns = boardWithFleet.getBoardColumns();
        borderX = 56 + (20 - numColumns)*10;
        borderY = 124 + (20 - numRows)*10;

        for(row = 0; row<numRows; row++)
        {
            for(column=0; column<numColumns; column++)
            {
                setfillstyle(SOLID_FILL, DARKGRAY);
                tempCell = boardWithFleet.getCellByLocation(row, column);

                if(tempCell->getOccupant() != NULL)
                {
                    left = borderX + 20 * column + 1;
                    right = borderX + 20 * (column + 1);
                    top = borderY + 20 * row + 1;
                    bottom = borderY + 20 * (row + 1);
                    bar3d(left, top, right, bottom, 0, 1);
                }
            }
        }
    }
//----------------------------------------------------------------------------------------------------------//
    Coordinate* Graphical::getCoordinate(Board currentBoard, unsigned boardOffsetX)
    {
        int mouseX, mouseY, borderX, borderY;
        unsigned numColumns, numRows, row, column;
        Coordinate* theCoordinate;

        numRows = currentBoard.getBoardRows();
        numColumns = currentBoard.getBoardColumns();
        borderX = boardOffsetX + (20 - numColumns)*10;
        borderY = 128 + (20 - numRows)*10;

        if(ismouseclick(WM_LBUTTONDOWN) == true)
        {
            getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
            row = (mouseY - borderY) / 20; //Integer division comes in handy here;
            column = (mouseX - borderX) / 20;

            if(row < currentBoard.getBoardRows() && column < currentBoard.getBoardColumns())
            {

                theCoordinate = new Coordinate;
                theCoordinate->init_SpecificCoordinate(row, column);
                clearmouseclick(WM_LBUTTONDOWN);
            }
            else
            {
                theCoordinate = NULL;
                clearmouseclick(WM_LBUTTONDOWN);
                cout << mouseY << " " << mouseX << endl;
            }
        }
        else
        {
            theCoordinate = NULL;
        }


        return theCoordinate;
    }
//----------------------------------------------------------------------------------------------------------//
}
