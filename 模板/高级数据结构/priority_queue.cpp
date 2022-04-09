#include <iostream>

using namespace std;

template<class T, const int MAX_SIZE> 
    class priority_queue {
        private: 
            T _node[MAX_SIZE];
            int _idx = 1;
            
            /*
             * the heap was current before we inserted a new node in it
             * the operation of inserting may destory the structure of heap
             * we need this operation to maintain the structure
             * 1) when we insert a node in heap, we will put it in the position which equals to idx in the array
             * 2) then we will swap the new node and the root node  
             * 3) the push_down operation only will make an influence on one side of heap
             * 4) the root of heap is the max node all of the node
            */  
            void push_down(int _t) {
                int _max = _t;

                if (_t << 1 < _idx && _node[_t << 1] < _node[_max]) {
                    _max = _t << 1;
                }

                if ((_t << 1) + 1 < _idx && _node[(_t << 1) + 1] < _node[_max]) {
                    _max = (_t << 1) + 1;
                }

                if (_max != _t) {
                    swap(_node[_max], _node[_t]);
                    push_down(_max);
                }
            }

            /**
             * a operation to maintain the structure of heap
             * it may be used when inserting and popping
             */
            void up(int _t) {
                if (_t >> 1 >= 1 && _node[_t >> 1] > _node[_t]) {
                    swap(_node[_t >> 1], _node[_t]);
                    up(_t >> 1);
                }
            }

        public:

            /**
             * the operation of inserting
             * when inserting, we put the new node in the end of array
             * then, we execute the operation of up
             * @param x 
             */
            void insert(T x) {
                _node[_idx] = x;
                up(_idx++);
            }

            /**
             * the operation of popping
             * when popping, we just swap the end of array and the root of heap
             * then, we execute the operation of down
             */
            void pop() {
                swap(_node[--_idx], _node[1]);
                push_down(1);
            }

            bool empty() {
                return _idx == 1;
            }

            T top() {
                return _node[1];
            }
    };

priority_queue<int, 1000005> pq;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a;

        if (a == 1) {
            cin >> b;
            pq.insert(b);
        } else if (a == 2) {
            cout << pq.top() << "\n";
        } else {
            pq.pop();
        }
    }

    // cout << pq.top();
    return 0;
}