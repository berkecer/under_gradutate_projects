#include <stdio.h>
#include <string.h>

/* Prototype of functions */
void Move(char PieceName[10],char Destination[10]);
void ShowMoves(char PieceName[10]);
void Initialize(void);
void Print(void);
void Exit(void);
void GetCommand(void);
void UpdateChessBoard(void);

char ChessBoard[8][8][2];  /* This array keeps every coordinates about every square on board.*/
char NameDigit_1[32];      /* This array keeps first digit of Piece Name's like 'P'*/
char NameDigit_2[32];      /* This array keeps second digit of Piece Name's like '1' */

char PlaceDigit_1[32];     /* This array keeps first digit of Place of same indexed Piece, like 'a' */
char PlaceDigit_2[32];     /* This array keeps second digit of Place of same indexed Piece, like '8' */

/* These two arrays just for checking(for example: What comes after a?, What comes before 3,etc.) */
char Letters[8]={'a','b','c','d','e','f','g','h'};
char Numbers[8]={'1','2','3','4','5','6','7','8'};


void main()
{
    printf("Chess Board Game in C Language \nHacettepe University\nBerk Ecer\n\n");
    Initialize(); /* At first game will initialize itself */
    UpdateChessBoard(); /* It will update itself */
    GetCommand(); /* Then it start asking commands */
}
void Move(char PieceName[10],char Destination[10])
{
    /* This function basically  finds the piece (checking all the 32 piece with for loop) that comes from input, checking its all possible moves
       like ShowMoves() function does. When loop comes every possible destination, it will add this destination's coordinates to arrays called
       -ValidMovesDigit-. Then it checkes if input destination is in our ValidMovesDigit arrays? if it is, piece will be moved. if not FAILED..
       For pawn i dont need a array like ValidMovesDigits because they can just move 1 square.
    */
    int i;
    for(i=0;i<32;i++)
    {
        if(NameDigit_1[i]==PieceName[0]&& NameDigit_2[i]==PieceName[1])
        {
            if(NameDigit_1[i]=='P') /* BLACK PAWN's MOVE */
            {
                int k;
                for(k=0;k<8;k++)
                {
                    int j;
                    for(j=0;j<8;j++)
                    {
                        if(ChessBoard[j][k][0]==PieceName[0] && ChessBoard[j][k][1]==PieceName[1])
                        {
                            if(ChessBoard[j][k+1][0]==' ')
                            {
                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            if(Letters[loop1]==Destination[0] && Numbers[loop2-1]==Destination[1])
                                            {
                                                PlaceDigit_1[i]=Destination[0];
                                                PlaceDigit_2[i]=Destination[1];
                                                printf("OK\n\n");
                                                break;
                                            }
                                            else
                                            {
                                                printf("FAILED\n\n");
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                printf("FAILED\n\n");
                            }

                        }
                    }
                }
            }
            else if(NameDigit_1[i]=='p')  /* WHITE PAWN's MOVE */
            {
                int k;
                for(k=0;k<8;k++)
                {
                    int j;
                    for(j=0;j<8;j++)
                    {
                        if(ChessBoard[j][k][0]==PieceName[0] && ChessBoard[j][k][1]==PieceName[1])
                        {
                            if(ChessBoard[j][k-1][0]==' ')
                            {
                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            if(Letters[loop1]==Destination[0] && Numbers[loop2+1]==Destination[1])
                                            {
                                                PlaceDigit_1[i]=Destination[0];
                                                PlaceDigit_2[i]=Destination[1];
                                                printf("OK\n\n");
                                                break;
                                            }
                                            else
                                            {
                                                printf("FAILED\n\n");
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                printf("FAILED\n\n");
                            }


                        }
                    }
                }
            }
            else if(NameDigit_1[i]=='R' || NameDigit_1[i]=='r') /* ROOK's MOVE */
            {
                char ValidMovesDigit_1[10];
                char ValidMovesDigit_2[10];
                char ValidMovesIndexer=0;


                int k;
                for(k=0;k<8;k++)
                {
                    int j;
                    for(j=0;j<8;j++)
                    {
                        if(ChessBoard[j][k][0]==PieceName[0] && ChessBoard[j][k][1]==PieceName[1])
                        {

                            /* Downword */
                            if(ChessBoard[j][k+1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j][k+next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2-next];
                                                ValidMovesIndexer++;

                                            }

                                        }
                                    }
                                    next++;
                                }

                            }



                            /* Upword */
                            if(ChessBoard[j][k-1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j][k-next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2+next];
                                                ValidMovesIndexer++;
                                            }
                                        }
                                    }
                                    next++;
                                }

                            }


                            /*LEFT */

                            if(ChessBoard[j-1][k][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j-next][k][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1-next];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2];
                                                ValidMovesIndexer++;
                                            }
                                        }
                                    }
                                    next++;
                                }

                            }


                            /* RIGHT */
                            if(ChessBoard[j+1][k][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j+next][k][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1+next];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2];
                                                ValidMovesIndexer++;
                                            }
                                        }
                                    }
                                    next++;
                                }

                            }



                        }
                    }
                }
                int ECounter=0;
                int xx;
                for(xx=0;xx<=ValidMovesIndexer;xx++)
                {
                    if(Destination[0]==ValidMovesDigit_1[xx] && Destination[1]==ValidMovesDigit_2[xx])
                    {
                        PlaceDigit_1[i]=Destination[0];
                        PlaceDigit_2[i]=Destination[1];
                        ECounter=1;
                        printf("OK\n\n");
                    }



                }

                if(ECounter==0)
                {
                    printf("FAILED\n\n");
                }

            }
            else if(NameDigit_1[i]=='B' || NameDigit_1[i]=='b') /* BISHOP's MOVE */
            {
                char ValidMovesDigit_1[10];
                char ValidMovesDigit_2[10];
                char ValidMovesIndexer=0;


                int k;
                for(k=0;k<8;k++)
                {
                    int j;
                    for(j=0;j<8;j++)
                    {
                        if(ChessBoard[j][k][0]==PieceName[0] && ChessBoard[j][k][1]==PieceName[1])
                        {

                            /* DOWNWORD + RIGHT*/
                            if(ChessBoard[j+1][k+1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j+next][k+next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1+next];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2-next];
                                                ValidMovesIndexer++;
                                            }
                                        }
                                    }
                                    next++;
                                }

                            }


                            /*UPWORD + RIGHT*/
                            if(ChessBoard[j+1][k-1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j+next][k-next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1+next];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2+next];
                                                ValidMovesIndexer++;
                                            }
                                        }
                                    }
                                    next++;
                                }

                            }


                            /*DOWNWORD + LEFT*/

                            if(ChessBoard[j-1][k+1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j-next][k+next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1-next];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2-next];
                                                ValidMovesIndexer++;
                                            }
                                        }
                                    }
                                    next++;
                                }

                            }


                            /* UPWORD + LEFT*/
                            if(ChessBoard[j-1][k-1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j-next][k-next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1-next];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2+next];
                                                ValidMovesIndexer++;
                                            }
                                        }
                                    }
                                    next++;
                                }

                            }



                        }
                    }
                }

                int ECounter=0;
                int xx;
                for(xx=0;xx<=ValidMovesIndexer;xx++)
                {
                    if(Destination[0]==ValidMovesDigit_1[xx] && Destination[1]==ValidMovesDigit_2[xx])
                    {
                        PlaceDigit_1[i]=Destination[0];
                        PlaceDigit_2[i]=Destination[1];
                        ECounter=1;
                        printf("OK\n\n");
                    }



                }

                if(ECounter==0)
                {
                    printf("FAILED\n\n");
                }

            }
            else if(NameDigit_1[i]=='Q' || NameDigit_1[i]=='q') /* QUEEN's MOVE*/
            {
                char ValidMovesDigit_1[10];
                char ValidMovesDigit_2[10];
                char ValidMovesIndexer=0;


                int k;
                for(k=0;k<8;k++)
                {
                    int j;
                    for(j=0;j<8;j++)
                    {
                        if(ChessBoard[j][k][0]==PieceName[0] && ChessBoard[j][k][1]==PieceName[1])
                        {

                            /* Downword*/
                            if(ChessBoard[j][k+1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j][k+next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2-next];
                                                ValidMovesIndexer++;

                                            }

                                        }
                                    }
                                    next++;
                                }

                            }



                            /*Upword*/
                            if(ChessBoard[j][k-1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j][k-next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2+next];
                                                ValidMovesIndexer++;
                                            }
                                        }
                                    }
                                    next++;
                                }

                            }


                            /*LEFT*/

                            if(ChessBoard[j-1][k][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j-next][k][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1-next];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2];
                                                ValidMovesIndexer++;
                                            }
                                        }
                                    }
                                    next++;
                                }

                            }


                            /* RIGHT*/
                            if(ChessBoard[j+1][k][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j+next][k][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1+next];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2];
                                                ValidMovesIndexer++;
                                            }
                                        }
                                    }
                                    next++;
                                }

                            }

                            /* DOWNWORD + RIGHT*/
                            if(ChessBoard[j+1][k+1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j+next][k+next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1+next];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2-next];
                                                ValidMovesIndexer++;
                                            }
                                        }
                                    }
                                    next++;
                                }

                            }


                            /*UPWORD + RIGHT*/
                            if(ChessBoard[j+1][k-1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j+next][k-next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1+next];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2+next];
                                                ValidMovesIndexer++;
                                            }
                                        }
                                    }
                                    next++;
                                }

                            }


                            /*DOWNWORD + LEFT*/

                            if(ChessBoard[j-1][k+1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j-next][k+next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1-next];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2-next];
                                                ValidMovesIndexer++;
                                            }
                                        }
                                    }
                                    next++;
                                }

                            }


                            /* UPWORD + LEFT*/
                            if(ChessBoard[j-1][k-1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j-next][k-next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1-next];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2+next];
                                                ValidMovesIndexer++;
                                            }
                                        }
                                    }
                                    next++;
                                }

                            }



                        }
                    }
                }

                int ECounter=0;
                int xx;
                for(xx=0;xx<=ValidMovesIndexer;xx++)
                {
                    if(Destination[0]==ValidMovesDigit_1[xx] && Destination[1]==ValidMovesDigit_2[xx])
                    {
                        PlaceDigit_1[i]=Destination[0];
                        PlaceDigit_2[i]=Destination[1];
                        ECounter=1;
                        printf("OK\n\n");
                    }



                }

                if(ECounter==0)
                {
                    printf("FAILED\n\n");
                }




            }
            else if(NameDigit_1[i]=='K' || NameDigit_1[i]=='k') /* KING's MOVE */
            {
                char ValidMovesDigit_1[10];
                char ValidMovesDigit_2[10];
                char ValidMovesIndexer=0;

                int k;
                for(k=0;k<8;k++)
                {
                    int j;
                    for(j=0;j<8;j++)
                    {
                        if(ChessBoard[j][k][0]==PieceName[0] && ChessBoard[j][k][1]==PieceName[1])
                        {
                            /* Downword*/
                            if(ChessBoard[j][k+1][0]==' ')
                            {
                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1];
                                            ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2-1];
                                            ValidMovesIndexer++;
                                        }
                                    }
                                }

                            }


                            /*Upword*/
                            if(ChessBoard[j][k-1][0]==' ')
                            {

                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1];
                                                ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2+1];
                                                ValidMovesIndexer++;
                                            }
                                        }
                                    }


                            }


                            /*LEFT*/

                            if(ChessBoard[j-1][k][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1-1];
                                            ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2];
                                            ValidMovesIndexer++;
                                        }
                                    }
                                }


                            }


                            /* RIGHT*/
                            if(ChessBoard[j+1][k][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1+1];
                                            ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2];
                                            ValidMovesIndexer++;
                                        }
                                    }
                                }


                            }


                            /* DOWNWORD + RIGHT*/
                            if(ChessBoard[j+1][k+1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1+1];
                                            ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2-1];
                                            ValidMovesIndexer++;
                                        }
                                    }
                                }


                            }


                            /*UPWORD + RIGHT*/
                            if(ChessBoard[j+1][k-1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1+1];
                                            ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2+1];
                                            ValidMovesIndexer++;
                                        }
                                    }
                                }


                            }


                            /*DOWNWORD + LEFT*/

                            if(ChessBoard[j-1][k+1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1-1];
                                            ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2-1];
                                            ValidMovesIndexer++;
                                        }
                                    }
                                }


                            }


                            /* UPWORD + LEFT*/
                            if(ChessBoard[j-1][k-1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1-1];
                                            ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2+1];
                                            ValidMovesIndexer++;
                                        }
                                    }
                                }


                            }



                        }
                    }
                }

                int ECounter=0;
                int xx;
                for(xx=0;xx<=ValidMovesIndexer;xx++)
                {
                    if(Destination[0]==ValidMovesDigit_1[xx] && Destination[1]==ValidMovesDigit_2[xx])
                    {
                        PlaceDigit_1[i]=Destination[0];
                        PlaceDigit_2[i]=Destination[1];
                        ECounter=1;
                        printf("OK\n\n");
                    }



                }

                if(ECounter==0)
                {
                    printf("FAILED\n\n");
                }

            }
            else if(NameDigit_1[i]=='N' || NameDigit_1[i]=='n') /* KNIGHT's MOVE*/
            {
                char ValidMovesDigit_1[10];
                char ValidMovesDigit_2[10];
                char ValidMovesIndexer=0;


                int k;
                for(k=0;k<8;k++)
                {
                    int j;
                    for(j=0;j<8;j++)
                    {
                        if(ChessBoard[j][k][0]==PieceName[0] && ChessBoard[j][k][1]==PieceName[1])
                        {
                            /* ASSUME THAT KNIGHT's COORDINATES IS (X,Y)
                             MOVE TO (X-2)(Y-1)*/
                            if(ChessBoard[j-2][k-1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1-2];
                                            ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2+1];
                                            ValidMovesIndexer++;
                                        }
                                    }
                                }

                            }


                            /* MOVE TO (X-1)(Y-2)*/
                            if(ChessBoard[j-1][k-2][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1-1];
                                            ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2+2];
                                            ValidMovesIndexer++;
                                        }
                                    }
                                }

                            }


                            /* MOVE TO (X+1)(Y-2)*/
                            if(ChessBoard[j+1][k-2][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1+1];
                                            ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2+2];
                                            ValidMovesIndexer++;
                                        }
                                    }
                                }

                            }


                            /* MOVE TO (X+2)(Y-1)*/
                            if(ChessBoard[j+2][k-1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1+2];
                                            ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2+1];
                                            ValidMovesIndexer++;
                                        }
                                    }
                                }

                            }


                            /* MOVE TO (X+2)(Y+1)*/
                            if(ChessBoard[j+2][k+1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1+2];
                                            ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2-1];
                                            ValidMovesIndexer++;
                                        }
                                    }
                                }

                            }


                            /* MOVE TO (X+1)(Y+2)*/
                            if(ChessBoard[j+1][k+2][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1+1];
                                            ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2-2];
                                            ValidMovesIndexer++;
                                        }
                                    }
                                }

                            }


                            /* MOVE TO (X-1)(Y+2)*/
                            if(ChessBoard[j-1][k+2][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1-1];
                                            ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2-2];
                                            ValidMovesIndexer++;
                                        }
                                    }
                                }

                            }


                            /* MOVE TO (X-2)(Y+1)*/
                            if(ChessBoard[j-2][k+1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            ValidMovesDigit_1[ValidMovesIndexer]=Letters[loop1-2];
                                            ValidMovesDigit_2[ValidMovesIndexer]=Numbers[loop2-1];
                                            ValidMovesIndexer++;
                                        }
                                    }
                                }

                            }

                        }
                    }
                }

                int ECounter=0;
                int xx;
                for(xx=0;xx<=ValidMovesIndexer;xx++)
                {
                    if(Destination[0]==ValidMovesDigit_1[xx] && Destination[1]==ValidMovesDigit_2[xx])
                    {
                        PlaceDigit_1[i]=Destination[0];
                        PlaceDigit_2[i]=Destination[1];
                        ECounter=1;
                        printf("OK\n\n");
                    }



                }

                if(ECounter==0)
                {
                    printf("FAILED\n\n");
                }
            }


        }
    }






}
void ShowMoves(char PieceName[10])
{
    printf("Here is the possible moves about this piece %s...\n",PieceName);

    int i;
    for(i=0;i<32;i++)
    {
        if(NameDigit_1[i]==PieceName[0] && NameDigit_2[i]==PieceName[1])
        {
            if(NameDigit_1[i]=='P')  /* BLACK PAWN's  MOVE*/
            {
                int k;
                for(k=0;k<8;k++)
                {
                    int j;
                    for(j=0;j<8;j++)
                    {
                        if(ChessBoard[j][k][0]==PieceName[0] && ChessBoard[j][k][1]==PieceName[1])
                        {
                            if(ChessBoard[j][k+1][0]==' ')
                            {
                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c \n\n",Letters[loop1],Numbers[loop2-1]);
                                        }
                                    }
                                }
                            }
                            else
                            {
                                printf("OPERATION FAILED, There is no possible moves!! \n\n");
                            }

                        }
                    }
                }
            }
            else if(NameDigit_1[i]=='p') /* WHITE PAWN's MOVE*/
            {
                int k;
                for(k=0;k<8;k++)
                {
                    int j;
                    for(j=0;j<8;j++)
                    {
                        if(ChessBoard[j][k][0]==PieceName[0] && ChessBoard[j][k][1]==PieceName[1])
                        {
                            if(ChessBoard[j][k-1][0]==' ')
                            {
                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c \n\n",Letters[loop1],Numbers[loop2+1]);
                                        }
                                    }
                                }
                            }
                            else
                            {
                                printf("OPERATION FAILED, There is no possible moves!! \n\n");
                            }

                        }
                    }
                }
            }
            else if(NameDigit_1[i]=='R' || NameDigit_1[i]=='r') /* ROOK's MOVE*/
            {
                int ErrorCounter=0;
                int k;
                for(k=0;k<8;k++)
                {
                    int j;
                    for(j=0;j<8;j++)
                    {
                        if(ChessBoard[j][k][0]==PieceName[0] && ChessBoard[j][k][1]==PieceName[1])
                        {

                            /* Downword*/
                            if(ChessBoard[j][k+1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j][k+next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1],Numbers[loop2-next]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /*Upword*/
                            if(ChessBoard[j][k-1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j][k-next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1],Numbers[loop2+next]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }


                            /*LEFT*/
                            if(ChessBoard[j-1][k][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j-next][k][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1-next],Numbers[loop2]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /* RIGHT*/
                            if(ChessBoard[j+1][k][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j+next][k][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1+next],Numbers[loop2]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }


                        }
                    }
                }

                if(ErrorCounter==4)
                {
                    printf("FAILED\n\n");
                }
            }
            else if(NameDigit_1[i]=='B' || NameDigit_1[i]=='b') /* BISHOP's MOVE*/
            {
                int ErrorCounter=0;
                int k;
                for(k=0;k<8;k++)
                {
                    int j;
                    for(j=0;j<8;j++)
                    {
                        if(ChessBoard[j][k][0]==PieceName[0] && ChessBoard[j][k][1]==PieceName[1])
                        {

                            /* DOWNWORD + RIGHT*/
                            if(ChessBoard[j+1][k+1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j+next][k+next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1+next],Numbers[loop2-next]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /*UPWORD + RIGHT*/
                            if(ChessBoard[j+1][k-1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j+next][k-next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1+next],Numbers[loop2+next]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }


                            /*DOWNWORD + LEFT*/
                            if(ChessBoard[j-1][k+1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j-next][k+next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1-next],Numbers[loop2-next]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /* UPWORD + LEFT*/
                            if(ChessBoard[j-1][k-1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j-next][k-next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1-next],Numbers[loop2+next]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }


                        }
                    }
                }

                if(ErrorCounter==4)
                {
                    printf("FAILED\n\n");
                }
            }
            else if(NameDigit_1[i]=='Q' || NameDigit_1[i]=='q') /*QUEEN's MOVE*/
            {
                int ErrorCounter=0;
                int k;
                for(k=0;k<8;k++)
                {
                    int j;
                    for(j=0;j<8;j++)
                    {
                        if(ChessBoard[j][k][0]==PieceName[0] && ChessBoard[j][k][1]==PieceName[1])
                        {
                            /* Downword*/
                            if(ChessBoard[j][k+1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j][k+next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1],Numbers[loop2-next]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /*Upword*/
                            if(ChessBoard[j][k-1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j][k-next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1],Numbers[loop2+next]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /*LEFT*/

                            if(ChessBoard[j-1][k][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j-next][k][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1-next],Numbers[loop2]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /* RIGHT*/
                            if(ChessBoard[j+1][k][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j+next][k][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1+next],Numbers[loop2]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /* DOWNWORD + RIGHT*/
                            if(ChessBoard[j+1][k+1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j+next][k+next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1+next],Numbers[loop2-next]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /*UPWORD + RIGHT*/
                            if(ChessBoard[j+1][k-1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j+next][k-next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1+next],Numbers[loop2+next]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /*DOWNWORD + LEFT*/

                            if(ChessBoard[j-1][k+1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j-next][k+next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1-next],Numbers[loop2-next]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /* UPWORD + LEFT*/
                            if(ChessBoard[j-1][k-1][0]==' ')
                            {
                                int next =1;
                                while(ChessBoard[j-next][k-next][0]==' ')
                                {
                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1-next],Numbers[loop2+next]);
                                            }
                                        }
                                    }
                                    next++;
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }


                        }
                    }
                }

                if(ErrorCounter==8)
                {
                    printf("FAILED\n\n");
                }
            }
            else if(NameDigit_1[i]=='K' || NameDigit_1[i]=='k') /* KING's MOVE*/
            {
                int ErrorCounter=0;
                int k;
                for(k=0;k<8;k++)
                {
                    int j;
                    for(j=0;j<8;j++)
                    {
                        if(ChessBoard[j][k][0]==PieceName[0] && ChessBoard[j][k][1]==PieceName[1])
                        {
                            /* Downword*/
                            if(ChessBoard[j][k+1][0]==' ')
                            {
                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c  ",Letters[loop1],Numbers[loop2-1]);
                                        }
                                    }
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /*Upword*/
                            if(ChessBoard[j][k-1][0]==' ')
                            {

                                    int loop1;
                                    for(loop1=0;loop1<8;loop1++)
                                    {
                                        int loop2;
                                        for(loop2=0;loop2<8;loop2++)
                                        {
                                            if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                            {
                                                printf("%c%c  ",Letters[loop1],Numbers[loop2+1]);
                                            }
                                        }
                                    }

                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /*LEFT*/

                            if(ChessBoard[j-1][k][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c  ",Letters[loop1-1],Numbers[loop2]);
                                        }
                                    }
                                }

                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /* RIGHT*/
                            if(ChessBoard[j+1][k][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c  ",Letters[loop1+1],Numbers[loop2]);
                                        }
                                    }
                                }

                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /* DOWNWORD + RIGHT*/
                            if(ChessBoard[j+1][k+1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c  ",Letters[loop1+1],Numbers[loop2-1]);
                                        }
                                    }
                                }

                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /*UPWORD + RIGHT*/
                            if(ChessBoard[j+1][k-1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c  ",Letters[loop1+1],Numbers[loop2+1]);
                                        }
                                    }
                                }

                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /*DOWNWORD + LEFT*/

                            if(ChessBoard[j-1][k+1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c  ",Letters[loop1-1],Numbers[loop2-1]);
                                        }
                                    }
                                }

                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /* UPWORD + LEFT*/
                            if(ChessBoard[j-1][k-1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c  ",Letters[loop1-1],Numbers[loop2+1]);
                                        }
                                    }
                                }

                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }


                        }
                    }
                }

                if(ErrorCounter==8)
                {
                    printf("FAILED\n\n");
                }
            }
            else if(NameDigit_1[i]=='N' || NameDigit_1[i]=='n') /* KNIGHT's MOVE*/
            {
                int ErrorCounter=0;
                int k;
                for(k=0;k<8;k++)
                {
                    int j;
                    for(j=0;j<8;j++)
                    {
                        if(ChessBoard[j][k][0]==PieceName[0] && ChessBoard[j][k][1]==PieceName[1])
                        {
                            /* ASSUME THAT KNIGHT's COORDINATES IS (X,Y)*/
                            /* MOVE TO (X-2)(Y-1)*/
                            if(ChessBoard[j-2][k-1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c  ",Letters[loop1-2],Numbers[loop2+1]);
                                        }
                                    }
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /* MOVE TO (X-1)(Y-2)*/
                            if(ChessBoard[j-1][k-2][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c  ",Letters[loop1-1],Numbers[loop2+2]);
                                        }
                                    }
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /* MOVE TO (X+1)(Y-2)*/
                            if(ChessBoard[j+1][k-2][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c  ",Letters[loop1+1],Numbers[loop2+2]);
                                        }
                                    }
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /* MOVE TO (X+2)(Y-1)*/
                            if(ChessBoard[j+2][k-1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c  ",Letters[loop1+2],Numbers[loop2+1]);
                                        }
                                    }
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /* MOVE TO (X+2)(Y+1)*/
                            if(ChessBoard[j+2][k+1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c  ",Letters[loop1+2],Numbers[loop2-1]);
                                        }
                                    }
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /* MOVE TO (X+1)(Y+2)*/
                            if(ChessBoard[j+1][k+2][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c  ",Letters[loop1+1],Numbers[loop2-2]);
                                        }
                                    }
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /* MOVE TO (X-1)(Y+2)*/
                            if(ChessBoard[j-1][k+2][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c  ",Letters[loop1-1],Numbers[loop2-2]);
                                        }
                                    }
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }

                            /*MOVE TO (X-2)(Y+1)*/
                            if(ChessBoard[j-2][k+1][0]==' ')
                            {

                                int loop1;
                                for(loop1=0;loop1<8;loop1++)
                                {
                                    int loop2;
                                    for(loop2=0;loop2<8;loop2++)
                                    {
                                        if(Letters[loop1]==PlaceDigit_1[i]&&Numbers[loop2]==PlaceDigit_2[i])
                                        {
                                            printf("%c%c  ",Letters[loop1-2],Numbers[loop2-1]);
                                        }
                                    }
                                }
                                printf("\n");
                            }
                            else
                            {
                                ErrorCounter++;
                            }
                        }
                    }
                }

                if(ErrorCounter==8)
                {
                    printf("FAILED\n\n");
                }
            }



        }
    }
}
void Initialize()
{
    /* Empties the Chessboard, if we dont program will show us <null>*/
    int w;
    for(w=0;w<8;w++)
    {
        int q;
        for(q=0;q<8;q++)
        {
            int t;
            for(t=0;t<2;t++)
            {
                ChessBoard[q][w][t]=' ';
            }
        }
    }

    /* This arrays keeps Original Chess Board, with pieces on their first place*/
    char NameDigit_1_StartPosition[32] = {'R','N','B','Q','K','B','N','R','P','P','P','P','P','P','P','P','p','p','p','p','p','p','p','p','r','n','b','q','k','b','n','r'};
    char NameDigit_2_StartPosition[32] = {'1','1','1','U','I','2','2','2','1','2','3','4','5','6','7','8','1','2','3','4','5','6','7','8','1','1','1','u','i','2','2','2'};

    char PlaceDigit_1_StartPosition[32]= {'a','b','c','d','e','f','g','h','a','b','c','d','e','f','g','h','a','b','c','d','e','f','g','h','a','b','c','d','e','f','g','h'};
    char PlaceDigit_2_StartPosition[32]= {'8','8','8','8','8','8','8','8','7','7','7','7','7','7','7','7','2','2','2','2','2','2','2','2','1','1','1','1','1','1','1','1'};

    /* Than i add these initial description to Current Game, loading the board and pieces*/
    memcpy(NameDigit_1, NameDigit_1_StartPosition, sizeof NameDigit_1);
    memcpy(NameDigit_2, NameDigit_2_StartPosition, sizeof NameDigit_2);
    memcpy(PlaceDigit_1, PlaceDigit_1_StartPosition, sizeof PlaceDigit_1);
    memcpy(PlaceDigit_2, PlaceDigit_2_StartPosition, sizeof PlaceDigit_2);

    printf("Initialization: OK \n\n");
}
void Print()
{
    UpdateChessBoard();

    printf("\nCurrent game...\n\n");

    /*This Loop prints the all items in chessboard*/
    int w;
    for(w=0;w<8;w++)
    {
        int q;
        for(q=0;q<8;q++)
        {
            int t;
            for(t=0;t<2;t++)
            {
                printf("%c",ChessBoard[q][w][t]);
            }

            printf("   ");
        }
        printf("\n\n");
    }
}
void UpdateChessBoard()
{
    /* Clears the chessboard for new*/
    int w;
    for(w=0;w<8;w++)
    {
        int q;
        for(q=0;q<8;q++)
        {
            int t;
            for(t=0;t<2;t++)
            {
                ChessBoard[q][w][t]=' ';
            }
        }
    }

    /* Puts The Current Pieces on their current places*/
    int y;
    for(y=0;y<32;y++)
    {
        switch(PlaceDigit_1[y])
        {
            case 'a':
            {
                switch(PlaceDigit_2[y])
                {
                    case '8':
                    {
                       ChessBoard[0][0][0]= NameDigit_1[y];
                       ChessBoard[0][0][1]= NameDigit_2[y];
                       break;
                    }
                    case '7':
                    {
                       ChessBoard[0][1][0]= NameDigit_1[y];
                       ChessBoard[0][1][1]= NameDigit_2[y];
                       break;
                    }
                    case '6':
                    {
                       ChessBoard[0][2][0]= NameDigit_1[y];
                       ChessBoard[0][2][1]= NameDigit_2[y];
                       break;
                    }
                    case '5':
                    {
                       ChessBoard[0][3][0]= NameDigit_1[y];
                       ChessBoard[0][3][1]= NameDigit_2[y];
                       break;
                    }
                    case '4':
                    {
                       ChessBoard[0][4][0]= NameDigit_1[y];
                       ChessBoard[0][4][1]= NameDigit_2[y];
                       break;
                    }
                    case '3':
                    {
                       ChessBoard[0][5][0]= NameDigit_1[y];
                       ChessBoard[0][5][1]= NameDigit_2[y];
                       break;
                    }
                     case '2':
                    {
                       ChessBoard[0][6][0]= NameDigit_1[y];
                       ChessBoard[0][6][1]= NameDigit_2[y];
                       break;
                    }
                     case '1':
                    {
                       ChessBoard[0][7][0]= NameDigit_1[y];
                       ChessBoard[0][7][1]= NameDigit_2[y];
                       break;
                    }
                }
                break;
            }
            case 'b':
            {
                switch(PlaceDigit_2[y])
                {
                    case '8':
                    {
                       ChessBoard[1][0][0]= NameDigit_1[y];
                       ChessBoard[1][0][1]= NameDigit_2[y];
                       break;
                       break;
                    }
                    case '7':
                    {
                       ChessBoard[1][1][0]= NameDigit_1[y];
                       ChessBoard[1][1][1]= NameDigit_2[y];
                       break;
                    }
                    case '6':
                    {
                       ChessBoard[1][2][0]= NameDigit_1[y];
                       ChessBoard[1][2][1]= NameDigit_2[y];
                       break;
                    }
                    case '5':
                    {
                       ChessBoard[1][3][0]= NameDigit_1[y];
                       ChessBoard[1][3][1]= NameDigit_2[y];
                       break;
                    }
                    case '4':
                    {
                       ChessBoard[1][4][0]= NameDigit_1[y];
                       ChessBoard[1][4][1]= NameDigit_2[y];
                       break;
                    }
                    case '3':
                    {
                       ChessBoard[1][5][0]= NameDigit_1[y];
                       ChessBoard[1][5][1]= NameDigit_2[y];
                       break;
                    }
                     case '2':
                    {
                       ChessBoard[1][6][0]= NameDigit_1[y];
                       ChessBoard[1][6][1]= NameDigit_2[y];
                       break;
                    }
                     case '1':
                    {
                       ChessBoard[1][7][0]= NameDigit_1[y];
                       ChessBoard[1][7][1]= NameDigit_2[y];
                       break;
                    }
                }
                break;
            }
            case 'c':
            {
                switch(PlaceDigit_2[y])
                {
                    case '8':
                    {
                       ChessBoard[2][0][0]= NameDigit_1[y];
                       ChessBoard[2][0][1]= NameDigit_2[y];
                       break;
                    }
                    case '7':
                    {
                       ChessBoard[2][1][0]= NameDigit_1[y];
                       ChessBoard[2][1][1]= NameDigit_2[y];
                       break;
                    }
                    case '6':
                    {
                       ChessBoard[2][2][0]= NameDigit_1[y];
                       ChessBoard[2][2][1]= NameDigit_2[y];
                       break;
                    }
                    case '5':
                    {
                       ChessBoard[2][3][0]= NameDigit_1[y];
                       ChessBoard[2][3][1]= NameDigit_2[y];
                       break;
                    }
                    case '4':
                    {
                       ChessBoard[2][4][0]= NameDigit_1[y];
                       ChessBoard[2][4][1]= NameDigit_2[y];
                       break;
                    }
                    case '3':
                    {
                       ChessBoard[2][5][0]= NameDigit_1[y];
                       ChessBoard[2][5][1]= NameDigit_2[y];
                       break;
                    }
                     case '2':
                    {
                       ChessBoard[2][6][0]= NameDigit_1[y];
                       ChessBoard[2][6][1]= NameDigit_2[y];
                       break;
                    }
                     case '1':
                    {
                       ChessBoard[2][7][0]= NameDigit_1[y];
                       ChessBoard[2][7][1]= NameDigit_2[y];
                       break;
                    }
                }
                break;
            }
            case 'd':
            {
                switch(PlaceDigit_2[y])
                {
                    case '8':
                    {
                       ChessBoard[3][0][0]= NameDigit_1[y];
                       ChessBoard[3][0][1]= NameDigit_2[y];
                       break;
                    }
                    case '7':
                    {
                       ChessBoard[3][1][0]= NameDigit_1[y];
                       ChessBoard[3][1][1]= NameDigit_2[y];
                       break;
                    }
                    case '6':
                    {
                       ChessBoard[3][2][0]= NameDigit_1[y];
                       ChessBoard[3][2][1]= NameDigit_2[y];
                       break;
                    }
                    case '5':
                    {
                       ChessBoard[3][3][0]= NameDigit_1[y];
                       ChessBoard[3][3][1]= NameDigit_2[y];
                       break;
                    }
                    case '4':
                    {
                       ChessBoard[3][4][0]= NameDigit_1[y];
                       ChessBoard[3][4][1]= NameDigit_2[y];
                       break;
                    }
                    case '3':
                    {
                       ChessBoard[3][5][0]= NameDigit_1[y];
                       ChessBoard[3][5][1]= NameDigit_2[y];
                       break;
                    }
                     case '2':
                    {
                       ChessBoard[3][6][0]= NameDigit_1[y];
                       ChessBoard[3][6][1]= NameDigit_2[y];
                       break;
                    }
                     case '1':
                    {
                       ChessBoard[3][7][0]= NameDigit_1[y];
                       ChessBoard[3][7][1]= NameDigit_2[y];
                       break;
                    }
                }
                break;
            }
            case 'e':
            {
                switch(PlaceDigit_2[y])
                {
                    case '8':
                    {
                       ChessBoard[4][0][0]= NameDigit_1[y];
                       ChessBoard[4][0][1]= NameDigit_2[y];
                       break;
                    }
                    case '7':
                    {
                       ChessBoard[4][1][0]= NameDigit_1[y];
                       ChessBoard[4][1][1]= NameDigit_2[y];
                       break;
                    }
                    case '6':
                    {
                       ChessBoard[4][2][0]= NameDigit_1[y];
                       ChessBoard[4][2][1]= NameDigit_2[y];
                       break;
                    }
                    case '5':
                    {
                       ChessBoard[4][3][0]= NameDigit_1[y];
                       ChessBoard[4][3][1]= NameDigit_2[y];
                       break;
                    }
                    case '4':
                    {
                       ChessBoard[4][4][0]= NameDigit_1[y];
                       ChessBoard[4][4][1]= NameDigit_2[y];
                       break;
                    }
                    case '3':
                    {
                       ChessBoard[4][5][0]= NameDigit_1[y];
                       ChessBoard[4][5][1]= NameDigit_2[y];
                       break;
                    }
                     case '2':
                    {
                       ChessBoard[4][6][0]= NameDigit_1[y];
                       ChessBoard[4][6][1]= NameDigit_2[y];
                       break;
                    }
                     case '1':
                    {
                       ChessBoard[4][7][0]= NameDigit_1[y];
                       ChessBoard[4][7][1]= NameDigit_2[y];
                       break;
                    }
                }
                break;
            }
            case 'f':
            {
                switch(PlaceDigit_2[y])
                {
                    case '8':
                    {
                       ChessBoard[5][0][0]= NameDigit_1[y];
                       ChessBoard[5][0][1]= NameDigit_2[y];
                       break;
                    }
                    case '7':
                    {
                       ChessBoard[5][1][0]= NameDigit_1[y];
                       ChessBoard[5][1][1]= NameDigit_2[y];
                       break;
                    }
                    case '6':
                    {
                       ChessBoard[5][2][0]= NameDigit_1[y];
                       ChessBoard[5][2][1]= NameDigit_2[y];
                       break;
                    }
                    case '5':
                    {
                       ChessBoard[5][3][0]= NameDigit_1[y];
                       ChessBoard[5][3][1]= NameDigit_2[y];
                       break;
                    }
                    case '4':
                    {
                       ChessBoard[5][4][0]= NameDigit_1[y];
                       ChessBoard[5][4][1]= NameDigit_2[y];
                       break;
                    }
                    case '3':
                    {
                       ChessBoard[5][5][0]= NameDigit_1[y];
                       ChessBoard[5][5][1]= NameDigit_2[y];
                       break;
                    }
                     case '2':
                    {
                       ChessBoard[5][6][0]= NameDigit_1[y];
                       ChessBoard[5][6][1]= NameDigit_2[y];
                       break;
                    }
                     case '1':
                    {
                       ChessBoard[5][7][0]= NameDigit_1[y];
                       ChessBoard[5][7][1]= NameDigit_2[y];
                       break;
                    }
                }
                break;
            }
            case 'g':
            {
                switch(PlaceDigit_2[y])
                {
                    case '8':
                    {
                       ChessBoard[6][0][0]= NameDigit_1[y];
                       ChessBoard[6][0][1]= NameDigit_2[y];
                       break;
                    }
                    case '7':
                    {
                       ChessBoard[6][1][0]= NameDigit_1[y];
                       ChessBoard[6][1][1]= NameDigit_2[y];
                       break;
                    }
                    case '6':
                    {
                       ChessBoard[6][2][0]= NameDigit_1[y];
                       ChessBoard[6][2][1]= NameDigit_2[y];
                       break;
                    }
                    case '5':
                    {
                       ChessBoard[6][3][0]= NameDigit_1[y];
                       ChessBoard[6][3][1]= NameDigit_2[y];
                       break;
                    }
                    case '4':
                    {
                       ChessBoard[6][4][0]= NameDigit_1[y];
                       ChessBoard[6][4][1]= NameDigit_2[y];
                       break;
                    }
                    case '3':
                    {
                       ChessBoard[6][5][0]= NameDigit_1[y];
                       ChessBoard[6][5][1]= NameDigit_2[y];
                       break;
                    }
                     case '2':
                    {
                       ChessBoard[6][6][0]= NameDigit_1[y];
                       ChessBoard[6][6][1]= NameDigit_2[y];
                       break;
                    }
                     case '1':
                    {
                       ChessBoard[6][7][0]= NameDigit_1[y];
                       ChessBoard[6][7][1]= NameDigit_2[y];
                       break;
                    }
                }
                break;
            }
            case 'h':
            {
                switch(PlaceDigit_2[y])
                {
                    case '8':
                    {
                       ChessBoard[7][0][0]= NameDigit_1[y];
                       ChessBoard[7][0][1]= NameDigit_2[y];
                       break;
                    }
                    case '7':
                    {
                       ChessBoard[7][1][0]= NameDigit_1[y];
                       ChessBoard[7][1][1]= NameDigit_2[y];
                       break;
                    }
                    case '6':
                    {
                       ChessBoard[7][2][0]= NameDigit_1[y];
                       ChessBoard[7][2][1]= NameDigit_2[y];
                       break;
                    }
                    case '5':
                    {
                       ChessBoard[7][3][0]= NameDigit_1[y];
                       ChessBoard[7][3][1]= NameDigit_2[y];
                       break;
                    }
                    case '4':
                    {
                       ChessBoard[7][4][0]= NameDigit_1[y];
                       ChessBoard[7][4][1]= NameDigit_2[y];
                       break;
                    }
                    case '3':
                    {
                       ChessBoard[7][5][0]= NameDigit_1[y];
                       ChessBoard[7][5][1]= NameDigit_2[y];
                       break;
                    }
                     case '2':
                    {
                       ChessBoard[7][6][0]= NameDigit_1[y];
                       ChessBoard[7][6][1]= NameDigit_2[y];
                       break;
                    }
                     case '1':
                    {
                       ChessBoard[7][7][0]= NameDigit_1[y];
                       ChessBoard[7][7][1]= NameDigit_2[y];
                       break;
                    }
                }
                break;
            }
        }
    }
}
void Exit()
{
    printf("THANKS FOR PLAYING...\n\n");
}
void GetCommand()
{
    /* These fucntion is getting and deciding commands, i need it because i must use Recursion for asking commands one-by-one.*/
   char CommandWord1[10];
   char CommandWord2[10];
   char CommandWord3[10];

   printf("> ");
   scanf("%s",CommandWord1);

   if(strcmp("move",CommandWord1)==0)
   {
       scanf("%s",CommandWord2);
       scanf("%s",CommandWord3);
       Move(CommandWord2,CommandWord3);
       UpdateChessBoard();
       GetCommand();
   }
   else if(strcmp("showmoves",CommandWord1)==0)
   {
       scanf("%s",CommandWord2);
       ShowMoves(CommandWord2);
       GetCommand();
   }
   else if(strcmp("initialize",CommandWord1)==0)
   {
       Initialize();
       GetCommand();
   }
   else if(strcmp("print",CommandWord1)==0)
   {
       Print();
       GetCommand();
   }
   else if(strcmp("exit",CommandWord1)==0)
   {
       Exit();
   }
   else
   {
       printf("Invalid Command, Please try again...\n\n");
       GetCommand();
   }
}


















