// тесты для вычисления арифметических выражений

#include <gtest.h>
#include "stack.h"

TEST(Parser, can_get_getType)
{
    char c = 'a';
    Parser a;
    EXPECT_EQ(a.getType(c), 1);
}

TEST(Parser, Parser_Massiv_Lexem) //разбиение строк на лексемы
{
    vector<Lexem> Lexems;
    Parser a;
    string s = "(1+1)";
    a.MassivLexem(s);
    Lexems = a.GetLexems();
    EXPECT_EQ(Lexems[0].str, "(");
    EXPECT_EQ(Lexems[0].type, 3);
    EXPECT_EQ(Lexems[1].str, "1");
    EXPECT_EQ(Lexems[1].type, 2);
    EXPECT_EQ(Lexems[2].str, "+");
    EXPECT_EQ(Lexems[2].type, 3);
    EXPECT_EQ(Lexems[3].str, "1");
    EXPECT_EQ(Lexems[3].type, 2);
    EXPECT_EQ(Lexems[4].str, ")");
    EXPECT_EQ(Lexems[4].type, 3);
}
TEST(Parser, Parser_Prioritets)
{
    Parser a;
    EXPECT_EQ(a.Prioritet(Lexem("(", 3)), 0);
    EXPECT_EQ(a.Prioritet(Lexem("+", 3)), 1);
    EXPECT_EQ(a.Prioritet(Lexem("-", 3)), 1);
    EXPECT_EQ(a.Prioritet(Lexem("*", 3)), 2);
    EXPECT_EQ(a.Prioritet(Lexem("/", 3)), 2); 
}
TEST(Parser, Delenie_na_nol) 
{
    Parser a;
    string s = "(5/0)";
    a.MassivLexem(s);
    a.Parser_Postfix();
    EXPECT_THROW(a.Arifmetic(), runtime_error); // Должно выбросить ошибку
}
TEST(Parser, Arithmetic) 
{
    Parser a;
    string s = "(2+2/2)";
    a.MassivLexem(s);
    a.Parser_Postfix();
    int res = a.Arifmetic();
    EXPECT_EQ(res, 3);
}
TEST(Parser, Parser_Massiv_Postfix)
{
    vector<Lexem> Postfix;
    Parser a;
    string s = "(3+4*2)";
    a.MassivLexem(s);
    a.Parser_Postfix();
    Postfix = a.GetPostfix();
    EXPECT_EQ(Postfix.size(), 5);
    EXPECT_EQ(Postfix[0].str, "3");
    EXPECT_EQ(Postfix[1].str, "4");
    EXPECT_EQ(Postfix[2].str, "2");
    EXPECT_EQ(Postfix[3].str, "*");
    EXPECT_EQ(Postfix[4].str, "+");
}
TEST(Parser, InvalidExpression) { // обработка некорректных выражений
    Parser a;
    // Тест на неправильный символ
    EXPECT_THROW(a.MassivLexem("5 + ! 3"), runtime_error);
    // Тест на недостаточное количество операторов
    EXPECT_THROW(a.MassivLexem("5 +"), runtime_error);
}

