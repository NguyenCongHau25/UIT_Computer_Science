score)
     {
        case 9:
        case 10:
            return 'A';
        case 8:
            return 'B';
        case 7:
            return 'C';
        case 6:
            return 'D';
        default: return 'F';
     }
}
int main()
{
    int score;
    cin >>score;
    score/=10;
    cout << courseGrade(score);
    return 0;
}