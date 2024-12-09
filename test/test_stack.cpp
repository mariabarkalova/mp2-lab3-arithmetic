// тесты для стека
#include <gtest.h>
#include "stack.h"

TEST(Stack, can_create_Stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> stack);
}
TEST(Stack, can_get_size)
{
	Stack<int> stack;
	EXPECT_EQ(0, stack.size());
}
TEST(Stack, can_get_Push)
{
	Stack<int> stack;
	stack.Push(10);
	EXPECT_EQ(stack.size(), 1);
}
TEST(Stack, can_get_IsEmpty)
{
	Stack<int> stack;
	EXPECT_TRUE(stack.IsEmpty());
}
TEST(Stack, can_get_Pop)
{
	Stack<int> stack;
	stack.Push(10);
	stack.Pop();
	EXPECT_EQ(stack.size(), 0);
}
TEST(Stack, can_get_Top)
{
	Stack<int> stack;
	stack.Push(10);
	EXPECT_EQ(stack.Top(), 10);
}
TEST(Stack, can_get_Pop_empty) // Проверка на попытку удаления элемента из пустого стека
{
	Stack<int> stack;
	EXPECT_THROW(stack.Pop(), std::runtime_error);
}
TEST(Stack, can_get_Top_empty) // Проверка на попытку доступа к верхнему элементу из пустого стека
{
	Stack<int> stack;
	EXPECT_THROW(stack.Top(), std::runtime_error);
}