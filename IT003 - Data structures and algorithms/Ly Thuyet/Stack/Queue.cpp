template <typename _DataType>
class queue
{
    private:
        _DataType Data[MAX];
        int nHead, nTail;

    public:
        queue() 
        { 
            nHead = nTail = 0; 
        }
        bool empty() 
        { 
            return ((nTail - nHead + MAX) % MAX == 0); 
        }
        void push(_DataType _data)
        {
            Data[nTail] = _data;
            nTail = (nTail + 1) % MAX;
        }
        void pop()
        {
            nHead = (nHead + 1) % MAX;
        }

        _DataType front()
        {
            return Data[(nHead)%MAX];
        }
            
        _DataType back() 
        {
           return Data[(nTail-1)%MAX]; 
        };
};