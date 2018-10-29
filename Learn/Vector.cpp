#include<iostream>
#include<vector>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int arr[] = {1,2,3,4,5,9,4,6,7,8,9,0};
    vector<int> first; // just start a vector
    vector<int> second(4,100); // start a vector with length 4 and all values set to 100
    vector<int> third(second.begin(), second.end()); // copy from a vector and start a new one
    vector<int> fourth(third); // another type of copy
    vector<int> fifth(arr,arr+sizeof(arr)/sizeof(arr[0])); // copy from an array
    //vector<int> sixth({10,20,30,40});





    // Vector insert
    vector<int> vecInsert;
    vector<int>::iterator it1, it2;
    vecInsert.push_back(1);
    vecInsert.push_back(2);
    vecInsert.push_back(3);
    it2 = vecInsert.begin();
    it2 = vecInsert.insert(it2, 10);
    vecInsert.insert(it2,2, 20); // position address, number, value
    vecInsert.insert(vecInsert.begin() + 1, 50); // insert 50 at position 2

    //Erase Vector
    vecInsert.erase(vecInsert.begin()); // erasing first element
    vecInsert.erase(vecInsert.begin()+2); // erasing 3rd element
    vecInsert.erase(vecInsert.begin(), vecInsert.begin() +3); // erase first 3 elements
   //Clear a vector
    //vecInsert.clear();

    /*
      std::vector<int> anothervector (2,400);
      myvector.insert (it+2,anothervector.begin(),anothervector.end());

      int myarray [] = { 501,502,503 };
      myvector.insert (myvector.begin(), myarray, myarray+3);
    */

    /*
    //testing iterator
    for(it1=vecInsert.begin();it1!=vecInsert.end();it1++){
        cout << *it1 << " ";
    }
    cout << endl;
    */




    /*
    #include<vector>
    vector<%data type%> %variable name% -> initialize a vector

    vec.begin() -> gives the address of  the vec's beginning
    vec.end() -> gives the address of  the vec's ending

    vec.push_back();
    vec.pop_back();
    sort(&@first,&@last)
    reverse(&@first, &@last)
    *max_element(&@first, &@last);
    *min_element(&@first, &@last);

    accumulate(&@first, &@last, initial sum value)
    count(&@first, &@last, value what to count)
    find(&@first, &@last, value what to find)

    */
    vector<int>vecBack({1,2,3,4});
    cout << vecBack.back() << endl;


    //cout << second.begin() << endl;
	return 0;
}
