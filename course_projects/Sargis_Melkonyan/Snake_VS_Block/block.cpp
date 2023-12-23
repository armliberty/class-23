#include "block.hpp"


Block::Block(){
    // std::array<std::array<char, length>, width> blockSize;
    coordY = 10;
}

void Block::valueDetermination(int val){
    blockValue = val;

}

void Block::valueReduce(){
    if(blockValue != 0){
        blockValue--;
    }
    //else ?
}

void Block::changeCoord(){
    if(coordY != 0){
        coordY++;
    }
}


void Block::bloksPushDoun(std::vector<Block> blocks){
    int i;
    for(i = 0; i < blocks.size(); ++i){
        blocks[i].changeCoord();
    }
}

void Block::blockGenerator(size_t value){
    int block_count = rand() % road_count; 

    int intvalue = (int)value;

    int intValue = static_cast<int>(value);

    std::cout << intValue;

    for(int i = 0; i < block_count; ++i){
        
        Block item;
        item.coordX = i*5;
        item.blockValue = rand() % 5;
        blocks.push_back(item);
    }
}