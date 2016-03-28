#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW (Stack<int> s(10));
}

TEST(Stack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> s(-1));
}

TEST(Stack, cant_create_stack_with_very_big_length)
{
	ASSERT_ANY_THROW(Stack<int> s(101));
}

TEST(Stack, can_get_size)
{
	Stack<int> s(2);
	EXPECT_EQ(2, s.getSize());
}

TEST(Stack, can_get_top)
{
	Stack<int> s(2);
	EXPECT_EQ(-1, s.getTop());
}

TEST(Stack,can_push)
{
	Stack<int> s(2);
	ASSERT_NO_THROW(s.push(1));
}

TEST(Stack,can_pop)
{
	Stack<int> s(2);
	s.push(1);
	ASSERT_NO_THROW(s.pop());
}

TEST(Stack,can_peek)
{
	Stack<int> s(2);
	s.push(2);
	EXPECT_EQ(2, s.peek());
}

TEST(Stack, cant_peek_empty_stack)
{
	Stack<int> s(2);
	ASSERT_ANY_THROW( s.peek());
}


TEST(Stack, peek_does_not_spoil_data) {
	Stack<int> s(2);
	s.push(1);
	s.push(2);
	s.peek();
	EXPECT_EQ(2, s.pop());
}

TEST(Stack, throws_when_full)
{
	Stack<int> s(2);
	s.push(1);
	s.push(2);
	ASSERT_ANY_THROW(s.push(3));
}
TEST(Stack, throws_when_free)
{
	Stack<int> s(2);
	ASSERT_ANY_THROW(s.pop());
}