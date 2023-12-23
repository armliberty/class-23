#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <array>
#include <iostream>
#include <random>
#include <vector>

class Block{
    private:
        static const size_t width = 5;
        static const size_t length = 5;
        static const size_t road_count = 5;
    
    public:
        std::vector<Block> blocks;
        int blockValue;
        int coordX;
        int coordY;
        const char symbol = 'b';

        Block();
        void valueDetermination(int val);
        void valueReduce();
        void changeCoord();
        void bloksPushDoun(std::vector<Block> blocks);
        void blockGenerator(size_t value);
        // std::array<std::array<char, width>, length> blockSize;
       
};

#endif
