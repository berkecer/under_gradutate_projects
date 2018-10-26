#ifndef BE_HEADER_H_INCLUDED
#define BE_HEADER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>

using namespace std;

template <class T>
class BE_Stack {
    public:
        // CLASS CONSTRUCTOR and DESTRUCTOR
        BE_Stack():top(0){
            ElementCount=0;
        }
        ~BE_Stack(){
            while (!IsEmpty()){
                Pop_LastElement();
            }
            IsEmpty();
        }

        // METHOD PROTOTYPES
        void Push_NewElement(const T& object);
        void Pop_LastElement();
        const T& Top_GetElement();
        int IsEmpty();
        int ElementCount;

    // Implementation of Linked List For endless STACK structure
    private:
        struct LinkedList_Node{
            T Node_Data;
            LinkedList_Node *Next_Node;

            // Node Initializer
            LinkedList_Node(const T& newData, LinkedList_Node *nextNode): Node_Data(newData), Next_Node(nextNode){}
        };
        LinkedList_Node *top;// top of stack

};


// can store both numbers and operators
class Line_Piece{
    //operator properties
    public: char operandSign[1];
    //number properties
    public: int numbers[100];
    public: int numbers_count;

    public:
        Line_Piece DeleteFirstZero(){
            Line_Piece lp = *this;
            int i;
            for(i=0;i<lp.numbers_count;i++){
                lp.numbers[i] = lp.numbers[i+1];
            }
            lp.numbers_count-=1;
            return lp;
        }


        void PrintNumber(FILE* outfile){
            Line_Piece lp = *this;
            int i;
            int limit = lp.numbers_count;
            for(i=0;i<limit;i++){
                fprintf(outfile,"%d",lp.numbers[i]);
            }
            fprintf(outfile,"\n");
        }
        Line_Piece Minus(){
            Line_Piece lp = *this;
            int i;
            int limit = lp.numbers_count;
            for(i=0;i<limit;i++){
                lp.numbers[i]=(-1)*lp.numbers[i];
            }

            return lp;
        }
        // POWER OVERLOAD
        Line_Piece operator/(const Line_Piece &RightNumber) const
        {
            Line_Piece LeftNumber = *this;
            /*
                71273123 | 123
                         |-----
                aradaki fark 5
            */
            // digit diference in 0 olma olasiligi da var
            int DigitDiference = LeftNumber.numbers_count - RightNumber.numbers_count;
            int ResultIndexer = 0;
            Line_Piece ResultOfDivision;
            Line_Piece TempNumberToDivide = LeftNumber;
            int i;
            for(i=0;i<=DigitDiference;i++){
                Line_Piece TempDivider = RightNumber;
                int DigitIndexer = RightNumber.numbers_count;
                int zc;
                for(zc=0;zc<DigitDiference-i;zc++){
                    TempDivider.numbers[DigitIndexer] = 0;
                    DigitIndexer++;
                }
                TempDivider.numbers_count = DigitIndexer;
                int counter1 = 0;
                while(TempNumberToDivide.numbers[0]>=0){
                    TempNumberToDivide = TempNumberToDivide - TempDivider;
                    counter1++;
                }
                TempNumberToDivide = TempNumberToDivide + TempDivider;
                ResultOfDivision.numbers[ResultIndexer] = counter1-1;
                ResultIndexer++;
            }
            ResultOfDivision.numbers_count = ResultIndexer;
            while(ResultOfDivision.numbers[0]==0 && ResultOfDivision.numbers_count>1){
                ResultOfDivision = ResultOfDivision.DeleteFirstZero();
            }

            return ResultOfDivision;

        }

        // POWER OVERLOAD
        Line_Piece operator^(const Line_Piece &RightNumber) const
        {
            Line_Piece LeftNumber = *this;
            Line_Piece ResultOfPower;
            int i;
            for(i=0;i<RightNumber.numbers[0];i++){
                if(i==0){
                    ResultOfPower = LeftNumber;
                }else{
                    ResultOfPower = ResultOfPower * LeftNumber;
                }
            }
            return ResultOfPower;
        }

        // MULTIPICATION OVERLOAD
        Line_Piece operator*(const Line_Piece &RightNumber) const
        {
            Line_Piece LeftNumber = *this;
            int pieceCount = 0;
            //I will save result here..
            Line_Piece ResultOfOperation;
            //for dynamic numbers indexes
            int LeftNumberMaxIndex = LeftNumber.numbers_count-1;
            int RightNumberMaxIndex = RightNumber.numbers_count-1;
            int ZeroCount = 0;

            int i = RightNumberMaxIndex;
            while(i>=0){
                int v1 = RightNumber.numbers[i];
                Line_Piece MultipicationPart;

                int j = LeftNumberMaxIndex;
                while(j>=0){
                    int v2 = LeftNumber.numbers[j];
                    int ResultOfMultPart = v1 * v2;
                    MultipicationPart.numbers[j]=ResultOfMultPart;
                    j--;
                }
                MultipicationPart.numbers_count=LeftNumberMaxIndex+1;


                //set the values again for >=10
                int k = LeftNumberMaxIndex;
                while(k>=0){
                        if(k!=0){
                            while(MultipicationPart.numbers[k]>=10){
                                if(k-1>=0){
                                    MultipicationPart.numbers[k]-=10;
                                    MultipicationPart.numbers[k-1]+=1;
                                }
                            }
                        }
                    k--;
                }


                Line_Piece MainResult;
                int ResultIndexer = 0;
                //check first number for >= 10

                int tmp=0;
                while(tmp<=LeftNumberMaxIndex){
                    if(tmp==0 && MultipicationPart.numbers[0]>=10){
                        MainResult.numbers[ResultIndexer]= MultipicationPart.numbers[tmp]/10;
                        ResultIndexer++;
                        MainResult.numbers[ResultIndexer] = MultipicationPart.numbers[tmp]%10;
                        ResultIndexer++;
                    }else{
                        MainResult.numbers[ResultIndexer] = MultipicationPart.numbers[tmp];
                        ResultIndexer++;
                    }

                    tmp++;
                }


                int zc;
                for(zc=0;zc<ZeroCount;zc++){
                    MainResult.numbers[ResultIndexer] = 0;
                    ResultIndexer++;
                }
                MainResult.numbers_count=ResultIndexer;
                if(pieceCount==0){
                    ResultOfOperation = MainResult;
                    pieceCount++;
                }else{
                    ResultOfOperation = ResultOfOperation + MainResult;
                }

                ZeroCount++;
                i--;
            }
            return ResultOfOperation;

        }

        // SUBTRACTION OVERLOAD
        Line_Piece operator-(const Line_Piece &RightNumber) const
        {
            Line_Piece LeftNumber = *this;
            //I will save result here..
            Line_Piece ResultOfOperation;

            //for dynamic numbers indexes
            int LeftNumberMaxIndex = LeftNumber.numbers_count-1;
            int RightNumberMaxIndex = RightNumber.numbers_count-1;

            //for loop limitation
            int LargestLenght = LeftNumber.numbers_count;
            if(RightNumber.numbers_count>LeftNumber.numbers_count){
                LargestLenght = RightNumber.numbers_count;
            }

            Line_Piece ResultWithErrors;
            ResultWithErrors.numbers_count=LargestLenght;
            // loop starts right side of the numbers
            int i;
            for(i=LargestLenght-1;i>=0;i--){
                int v1=0;
                int v2=0;

                if(LeftNumberMaxIndex>=0){ // if index is valid
                    v1=LeftNumber.numbers[LeftNumberMaxIndex];
                }
                if(RightNumberMaxIndex>=0){ // if index is valid
                    v2 = RightNumber.numbers[RightNumberMaxIndex];
                }

                int result = v1 - v2; //add the numbers
                ResultWithErrors.numbers[i]=result;

                LeftNumberMaxIndex--;
                RightNumberMaxIndex--;
            }

             //artanlari sola kaydiriyoruz
            int k;
            for(k=LargestLenght-1;k>=0;k--){
                if(ResultWithErrors.numbers[k]<0){
                    if(k-1>=0){
                        ResultWithErrors.numbers[k]+=10;
                        ResultWithErrors.numbers[k-1]-=1;
                    }
                }
            }


            //set the result value
            int checker = 0;
            int ResultCount = LargestLenght;
            int ResultIndexer = LargestLenght-1;
            int q;
            for(q=LargestLenght-1;q>=0;q--){
                if(ResultWithErrors.numbers[q]==0 && q==0){
                    checker++;
                }else{
                    if(ResultIndexer>=0){
                        ResultOfOperation.numbers[ResultIndexer] = ResultWithErrors.numbers[q];
                        ResultIndexer--;
                    }
                }
            }

            ResultOfOperation.numbers_count=ResultCount;

            if(checker>0){
                    if(ResultOfOperation.numbers_count != 1){
                        ResultOfOperation = ResultOfOperation.DeleteFirstZero();
                    }
            }

            return ResultOfOperation;
        }

         // ADDITION OVERLOAD
        Line_Piece operator+(const Line_Piece &RightNumber) const
        {
            Line_Piece LeftNumber = *this;
            //I will save result here..
            Line_Piece ResultOfOperation;

            //for dynamic numbers indexes
            int LeftNumberMaxIndex = LeftNumber.numbers_count-1;
            int RightNumberMaxIndex = RightNumber.numbers_count-1;

            //for loop limitation
            int LargestLenght = LeftNumber.numbers_count;
            if(RightNumber.numbers_count>LeftNumber.numbers_count){
                LargestLenght = RightNumber.numbers_count;
            }


            Line_Piece ResultWithErrors;
            ResultWithErrors.numbers_count=LargestLenght;
            // loop starts right side of the numbers
            int i;
            for(i=LargestLenght-1;i>=0;i--){
                int v1=0;
                int v2=0;

                if(LeftNumberMaxIndex>=0){ // if index is valid
                    v1=LeftNumber.numbers[LeftNumberMaxIndex];
                }
                if(RightNumberMaxIndex>=0){ // if index is valid
                    v2 = RightNumber.numbers[RightNumberMaxIndex];
                }

                int result = v1 + v2; //add the numbers
                ResultWithErrors.numbers[i]=result;

                LeftNumberMaxIndex--;
                RightNumberMaxIndex--;
            }

            //artanlari sola kaydiriyoruz
            int k;
            for(k=LargestLenght-1;k>=0;k--){
                if(ResultWithErrors.numbers[k]>=10){
                    if(k-1>=0){
                        ResultWithErrors.numbers[k]-=10;
                        ResultWithErrors.numbers[k-1]+=1;
                    }
                }
            }

            //set the result value
            int ResultCount = LargestLenght;
            int ResultIndexer = 0;
            int q;
            for(q=0;q<LargestLenght;q++){
                if(ResultWithErrors.numbers[q]>=10 && q==0){
                    ResultWithErrors.numbers[q]-=10;
                    ResultOfOperation.numbers[ResultIndexer]=1;
                    ResultIndexer++;
                    ResultCount++;
                }
                ResultOfOperation.numbers[ResultIndexer]=ResultWithErrors.numbers[q];
                ResultIndexer++;
            }
            ResultOfOperation.numbers_count=ResultCount;
            return ResultOfOperation;
        }
};



// Stack.Push(object) Function Template
template <class T>
void BE_Stack<T>::Push_NewElement(const T& obj){
    top = new LinkedList_Node(obj, top);
    ElementCount++;
}

// Stack.Pop() Function Template
template <class T>
void BE_Stack<T>::Pop_LastElement(){
    if (IsEmpty() == 1){
        LinkedList_Node *topNode = (LinkedList_Node*)malloc(sizeof(LinkedList_Node));
        topNode= top;
        top = top->Next_Node;
        delete topNode;
    }
    ElementCount--;
}

// Stack.Top() Function Template
template <class T>
const T& BE_Stack<T>::Top_GetElement() {
   return top->Node_Data;
}

// IsEmpty Function Template
template <class T>
int BE_Stack<T>::IsEmpty() {
    if (ElementCount == 0) {
        return 0;// empty
    }
    else {
        return 1; // not empty
    }
}



#endif // BE_HEADER_H_INCLUDED
