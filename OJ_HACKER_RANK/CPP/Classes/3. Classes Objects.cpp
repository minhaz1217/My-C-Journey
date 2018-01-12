class Student{
    int marks;
    public:
    Student(){
        marks = 0;
    }
    void input(){
        int a;
        for(int i=0;i<5;i++){
        cin >> a;
        marks+= a;

        }
        //cout << "A: " << a << " Marks: " << marks << endl;
    }
    int calculateTotalScore(){
        //cout << marks << endl;
        return marks;
    }

};
