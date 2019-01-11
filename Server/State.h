#ifndef SERVER_STATE_H
#define SERVER_STATE_H

template<class T>
class State {
public:
    State(T _state) : state(_state), cameFrom(nullptr) {}
    /*bool Equals(State<T> s)
    {
        return state.Equals(s.state);
    }*/

    State<T>* getCameFrom()
    {
        return cameFrom;
    }
    void setCameFrom(State<T>* _cameFrom)
    {
        cameFrom = _cameFrom;
    }
    double getCost() const
    {
        return cost;
    }
    void setCost(double _cost)
    {
        cost = _cost;
    }
    bool operator>(const State<T>& s) const
    {
        return cost > s.cost;
    }
    bool operator<(const State<T>& s) const
    {
        return cost < s.cost;
    }
    bool operator==(const State<T>& s) const
    {
        bool b = state == s.state;
        return state == s.state;
    }
    const T& getState() const
    {
        return state;
    }
    /*std::size_t operator()(const State<T>& myType) const {
        return 0; // Insert your hash here
    }*/

private:
    T state;
    double cost;
    State<T>* cameFrom;
};

template <class T>
bool comparator(const State<T>& lhs, const State<T>& rhs)
{
    return lhs.getState() > rhs.getState();
}
/*template <class T>
struct MyHash
{
    std::size_t operator()(const T& myType) const {
        return 0;
    }
};*/

/*auto myLambda = [](const State<T>& myType) {
    return 0;
};

decltype(myLambda)*/

/*template <class T>
int Compare(State<T>& s1, State<T>& s2)
{
    double cost1 = s1.getCost(), cost2 = s2.getCost();
    if (cost1 < cost2)
        return -1;
    if (cost1 == cost2)
        return 0;
    return 1;
}*/

#endif //SERVER_STATE_H
