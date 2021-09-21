#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* թվերի զանգվածում 0-ները տեղափոխել զանգվածի վերջ, պահպանելով ոչ 0-ական թվերի հերթականությունը. Օրինակ
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Խնդիրը պետք է լուծել առանց զանգվածը copy անելու՝ in-place
*/
/*
int main() {
  vector<int> arr;
    int lscp, size;
    cin >> size;
    lscp = 0;
    for(int j = 0; j < size; ++j)
    {
        int b;
        cin >> b;
        arr.push_back(b);
    }
    for (int i = 0 ; i < size ; ++i){
        if (arr[i] != 0)
        {
            arr[lscp] = arr[i];
            lscp++;
        }
    }
    for ( ; lscp < size ; ++lscp)
    {
        arr[lscp] = 0;
    }
    for (int i = 0 ; i < size ; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
*/

/*Տրված զանգվածում ամեն էլեմենտ փոխարինել իրենից աջ գտնվող էլեմենտներից ամենամեծով; Վերջին էլեմենտը փոխարինել -1-ով.
Input: [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]*/
int main(){
  int size;
  cin >> size;
  vector<int> arr;
  for(int i = 0; i < size; i++){
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }
  bool swapped;
  do{
    swapped = false;
    for(int i = 0; i< size; i++){
      if(arr[i] < arr[i + 1]){
        arr[i] = arr[i + 1];
       // arr[i + 1] = arr[i + 2];
        swapped = true;
      }
      
    }
  
  }while(swapped);
  arr[size - 2] = arr[size - 1];
  arr[size-1] = -1;
  for(int i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
  
}