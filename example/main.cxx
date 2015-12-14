#include <iostream>

#include "mutator.hxx"

using namespace std;

typedef pair<int,int>  ii_type;
typedef map<ii_type,double> ii2d_type;

class Foo
{
    public:
        Foo(double x):
            m_x(x)
        {
            m_ii2d[make_pair(2,4)] = 2.4;
            m_ii2d[make_pair(6,8)] = 6.8;
        }
    private:
        M_BUILTIN(double, x)
        M_BUILTIN_MAP(ii_type, double, ii2d)
};

class Bar
{
    public:
        Bar():
            m_foo(1.1)
        {
            m_vs.push_back("one");
            m_vs.push_back("tow");
        }
    private:
        M_INSTANCE(Foo, foo)
        M_BUILTIN_VECTOR(string, vs)
};

class Baz
{
    public:
        Baz():
            m_d2i(),
            m_vfoo(),
            m_d2bar()
        {
            m_d2i[2.] =  4;
            m_d2i[3.] =  9;
            m_d2i[4.] = 16;

            m_vfoo.push_back(Foo(7.0));
            m_vfoo.push_back(Foo(7.1));
            m_vfoo.push_back(Foo(7.2));

            m_d2bar[0.1] = Bar();
            m_d2bar[0.2] = Bar();
            m_d2bar[0.3] = Bar();
        }
    private:
        M_BUILTIN_MAP(double, int, d2i)
        M_INSTANCE_VECTOR(Foo, vfoo)
        M_INSTANCE_MAP(double, Bar, d2bar)
};

void
foo_demo()
{
    cout << "Foo demo" << endl;
    ii_type ii = make_pair(2,4);

    Foo foo(5.5);
    cout << foo.x() << endl;
    cout << foo.ii2d(ii) << endl;

    foo.set_x(6.6);
    foo.set_ii2d(ii, 4.2);

    cout << foo.x() << endl;
    cout << foo.ii2d(ii) << endl;
}

void
bar_demo()
{
    cout << "Bar demo" << endl;
    ii_type ii = make_pair(2,4);

    Bar bar;
    cout << bar.foo().x() << endl;
    cout << bar.foo().ii2d(ii) << endl;
    cout << bar.vs(0) << endl;
    cout << bar.vs(1) << endl;

    bar.foo().set_x(6.6);
    bar.foo().set_ii2d(ii, 4.2);
    bar.set_vs(0, "ONE");
    bar.set_vs(1, "TWO");

    cout << bar.foo().x() << endl;
    cout << bar.foo().ii2d(ii) << endl;
    cout << bar.vs(0) << endl;
    cout << bar.vs(1) << endl;
}

void
baz_demo()
{
    ii_type ii = make_pair(6,8);

    Baz baz;
    cout << baz.d2i(3.) << endl;
    cout << baz.vfoo(1).x() << endl;
    cout << baz.d2bar(0.1).foo().x() << endl;
    cout << baz.d2bar(0.2).foo().ii2d(ii) << endl;
    cout << baz.d2bar(0.3).vs(0) << endl;

    baz.set_d2i(3.,27);
    baz.vfoo(1).set_x(8.1);
    baz.d2bar(0.1).foo().set_x(9.1);
    baz.d2bar(0.2).foo().set_ii2d(ii,8.6);
    baz.d2bar(0.3).set_vs(0,"ONE");

    cout << baz.d2i(3.) << endl;
    cout << baz.vfoo(1).x() << endl;
    cout << baz.d2bar(0.1).foo().x() << endl;
    cout << baz.d2bar(0.2).foo().ii2d(ii) << endl;
    cout << baz.d2bar(0.3).vs(0) << endl;
}

int main()
{
    foo_demo();
    cout << endl;

    bar_demo();
    cout << endl;

    baz_demo();

    return 0;
}
