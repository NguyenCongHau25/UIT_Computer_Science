template <typename _DataType>
class stack
{
private:
    _DataType Data[MAX];
    int nTop;

public:
    stack()
    {
        nTop = 0;
    }
    bool empty()
    {
        return (nTop == 0);
    }
    void pop()
    {
        nTop--;
    }
    void push(_DataType _data)
    {
        Data[nTop] = _data;
        nTop = nTop + 1;
    }
    _DataType top()
    {
        return Data[nTop - 1];
    }
};