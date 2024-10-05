void getScore(int &score)
{   
    cout << "Enter course score (0<=score<=100): " ;
    cout<<endl;
    cin >> score;
    cout << "Course score is "<<score << endl;

}
void printGrade(int score)
{
    cout << "Your grade for the course is ";
    if (90<=score && score <=100) cout << "A";
    if (80<=score && score <=89) cout << "B";
    if (70<=score && score <=79) cout << "C";
    if (60<=score && score <=69) cout << "D";
    if (0<=score && score <=59) cout << "F";
}