#include "test.h"
#include "catch.hpp"

#include <cstring>
#include "DSString.h"
#include "linkedlist.h"
#include "linkednode.h"
#include "stack.h"

TEST_CASE("Linked List Class", "[Linked List]")
{
    LinkedList<int> a;
    a.insert(10);
    SECTION("Insert")
    {
        REQUIRE(a[0] == 10);
    }

    a.insert(15);
    a.insert(20);
    a.insert(25);
    a.insert(30);
    a.insert(35);
    a.insert(40);
    a.insert(10);

    SECTION("Equality operators")
    {
        REQUIRE(!(a[0] == a[5]));
        REQUIRE(a[3] == 25);
        REQUIRE((a[0] == a[7]));
    }

    SECTION("Remove")
    {
        a.remove();
        REQUIRE(a[a.getLength()-1] == 40);
        a.remove(2);
        REQUIRE(a[2] == 25);
        a.remove(0);
        REQUIRE(a[0] == 15);

    }

    SECTION("Pop")
    {
        REQUIRE(a.pop() == 10);
    }

    SECTION("Peek")
    {
        REQUIRE(a.peek() == 10);
        REQUIRE(a.peek() == a[a.getLength()-1]);
    }

    SECTION("isEmpty")
    {
        REQUIRE(a.isEmpty() != true);
        LinkedList<int> b;
        REQUIRE(b.isEmpty() == true);
        REQUIRE(a.isEmpty() != b.isEmpty());
    }

    SECTION("insert to middle")
    {
        a.insert(5,0);
        REQUIRE(a[0] == 5);
        REQUIRE(a[1] == 10);
        a.insert(50, a.getLength()-2);
        REQUIRE(a[9] == 10);
        REQUIRE(a[8] == 50);
    }
}

TEST_CASE("Stack Class", "[Stack]")
{
    Stack<int> a;
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);


    SECTION("peek")
    {
        REQUIRE(a.peek() == 50);
        a.push(60);
        REQUIRE(a.peek() == 60);
    }

    SECTION("pop")
    {
        REQUIRE(a.peek() == 50);
        REQUIRE(a.pop() == 50);
        REQUIRE(a.peek() == 40);
    }

    SECTION("isEmpty")
    {
        REQUIRE(a.isEmpty() == false);
        Stack<int> b;
        REQUIRE(b.isEmpty() == true);
    }

    SECTION("inStack")
    {
        REQUIRE(a.inStack(40) == true);
        REQUIRE(a.inStack(100) == false);
    }
}


