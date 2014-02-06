#ifndef COORDINATE_H
#define COORDINATE_H

using namespace std;

namespace Battleships
{
    class Coordinate
    {
        private:

        unsigned row;
        unsigned column;

        public:

        inline void init_SpecificCoordinate(unsigned aRow, unsigned aColumn) {row = aRow, column = aColumn;}
        void init_RandomCoordinate(unsigned maxRow, unsigned maxColumn);
        inline unsigned getCoordinateRow() {return row;}
        inline unsigned getCoordinateColumn() {return column;}
    };
}
#endif
