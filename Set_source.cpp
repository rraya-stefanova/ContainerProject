#include <iostream>
#include "Set.cpp"
#include "MultiSet.cpp"
#include "Container.cpp"

int main()
{
    Set<int> s;
    s.setName("alaa");
    int a, b, c;
    a = 5;
    b = 6;
    c = 7;
    s.addElement(a);
    s.addElement(b);
    s.addElement(c);
    s.print();

    MultiSet<int> m;
    m.addElement(a);
    m.addElement(a);
    // std::cout<<s[3];
    m.print();

    Set<char> **coll = new Set<char> *[3];
    Set<char> f1, f2;
    MultiSet<char> f3, f4;
    f1.addElement('A');
    f1.setName("ime1");
    f2.setName("ime2");

    f3.setName("ime3");

    f2.addElement('B');
    f3.addElement('W');
    f3.addElement('W');

    coll[0] = &f1;
    coll[1] = &f2;
    coll[2] = &f3;

    return 0;
}
