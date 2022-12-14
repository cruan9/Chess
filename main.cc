#include "pieces.h"
#include "board.h"
#include "observer.h"
#include <iostream>
#include <vector>
#include "player.h"

using namespace std;

void setDefaultBoard(Board* b){

    for(int i = 0; i < 8; i ++){
        b->placePiece('p', coord{i,6});
        b->placePiece('P', coord{i,1});
    }
    
    b->placePiece('r', coord{0,7});
    b->placePiece('n', coord{1,7});
    b->placePiece('b', coord{2,7});
    b->placePiece('q', coord{3,7});
    b->placePiece('k', coord{4,7});
    b->placePiece('b', coord{5,7});
    b->placePiece('n', coord{6,7});
    b->placePiece('r', coord{7,7});

    b->placePiece('R', coord{0,0});
    b->placePiece('N', coord{1,0});
    b->placePiece('B', coord{2,0});
    b->placePiece('Q', coord{3,0});
    b->placePiece('K', coord{4,0});
    b->placePiece('B', coord{5,0});
    b->placePiece('N', coord{6,0});
    b->placePiece('R', coord{7,0});
    
}

int main(){
    double whiteScore = 0;
    double blackScore = 0;
    Board *board = new Board;
    vector<Observer *> obs;

    TextObserver * newOb = new TextObserver(board);
    board->attach(newOb);
    obs.emplace_back(newOb);
    GraphicalObserver* graphOb = new GraphicalObserver(board);
    board->attach(graphOb);
    obs.emplace_back(graphOb);
    
    bool setBoard = false;          //if the board has been setup
    string command;
    
    while(cin >> command){          //command loop
        if(command == "game"){
            string player;              
            Player* p1;              //white
            Player* p2;              //black
            Player* curPlayer;
            char p1Color;
            if(!setBoard){
                setDefaultBoard(board);
                board->setTurn('w');
            }
            p1Color = board->getTurn();
            board->printBoard();

            while(cin >> player){
            if(player == "human"){
                    p1 = new Human(board);
                    break;
                }else if(player == "computer1"){
                    p1 = new Computer1(board);
                    break;
                }else if(player == "computer2"){
                    p1 = new Computer2(board);
                    break;
                }else if(player == "computer3"){
                    p1 = new Computer3(board);
                    break;
                }else if(player == "computer4"){
                    p1 = new Computer4(board);
                    break;
                }
            }
            while(cin >> player){
                if(player == "human"){
                    p2 = new Human(board);
                    break;
                }else if(player == "computer1"){
                    p2 = new Computer1(board);
                    break;
                }else if(player == "computer2"){
                    p2 = new Computer2(board);
                    break;
                }else if(player == "computer3"){
                    p2 = new Computer3(board);
                    break;
                }else if(player == "computer4"){
                    p2 = new Computer4(board);
                    break;
                }
            }
            if(board->getTurn()=='w'){
                cout << "White's turn: " <<endl;
            }else{
                cout << "Black's turn: " <<endl;
            }
            curPlayer = p1;
            while(curPlayer->move(whiteScore, blackScore)){   //game loop
                if(p1Color == board->getTurn()){
                    curPlayer = p1;
                }else{
                    curPlayer = p2;
                }

            }
                delete p1;
                delete p2;
        }else if(command == "setup"){
            setBoard = true;
            while(cin >> command){   //setup loop
                if(command == "+"){
                    char piece;
                    string pos;
                    cin >> piece >> pos;

                    board->placePiece(piece,coord{pos.at(0) - 'a',
                                                  pos.at(1) - '1'});
                    board->printBoard();
                }else if(command == "-"){
                    string pos;
                    cin >> pos;
                    board->removePiece(coord{pos.at(0) - 'a',
                                             pos.at(1) - '1'});
                    board->printBoard();
                }else if(command == "="){
                    string colour;
                    cin >> colour;
                    if(colour == "black" || colour == "b" || colour == "B"){
                        board->setTurn('b');
                    }else if(colour == "white" || colour == "w" || colour == "W"){
                        board->setTurn('w');
                    }
                }else if(command == "done"){
                    board->printBoard();
                    if(!board->setupCheck()){
                        cout << "Invalid board setup" << endl;
                    }
                    else break;
                }
            }
        }


    }
    delete board;

    cout << "Final Score:" << endl << "White: " << whiteScore << endl << "Black: " << blackScore << endl;
}
