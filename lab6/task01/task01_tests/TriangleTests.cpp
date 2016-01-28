﻿#include "stdafx.h"
#include "../Triangle.h"

using namespace std;

template <typename Ex, typename Fn>
void ExpectException(Fn && fn, const string & expectedDescription)
{
	// Проверяем, что вызов fn() выбросит исключение типа Ex 
	// с описанием, равным expectedDescription
	BOOST_CHECK_EXCEPTION(fn(), Ex, [&](const Ex& e){
		return e.what() == expectedDescription; 
	});

	/*
	try
	{

		fn(); // Выполняем действие, от которого ожидаем выброс исключения
		// Если не выбросило, то тест провалился
		BOOST_ERROR("No exception thrown");
	}
	catch (const Ex & e) // Ловим исключение типа Ex (или его подкласс)
	{
		// Проверяем, что исключение будет иметь ожидаемое сообщение
		BOOST_CHECK_EQUAL(expectedDescription, e.what());
	}
	catch (...)
	{
		// Если выбросили иное исключение, то это также ошибка
		BOOST_ERROR("Unexpected exception");
	}
	*/
}

template <typename Ex>
void ExpectConstructorFailure(double side1, double side2, double side3, const string & expectedDescription)
{
	ExpectException<Ex>([&]{
		CTriangle(side1, side2, side3); 
	}, expectedDescription);
}

BOOST_AUTO_TEST_SUITE(Triangle)
	BOOST_AUTO_TEST_CASE(cannot_have_negative_sides)
	{
		ExpectConstructorFailure<invalid_argument>(-1, 2, 3, "side1 can not be negative.");
		ExpectConstructorFailure<invalid_argument>(1, -2, 3, "Side 2 can not be negative.");

		ExpectException<invalid_argument>([]{
			CTriangle(1, 2, -3);
		}, "Side 3 can not be negative.");

		/*
		BOOST_CHECK_THROW(CTriangle(-1, 2, 3), invalid_argument);
		BOOST_CHECK_THROW(CTriangle(1, -2, 3), invalid_argument);
		BOOST_CHECK_THROW(CTriangle(1, 2, -3), invalid_argument);
		*/
	}

	struct when_created_
	{
		CTriangle t = CTriangle(3, 4, 5);
	};
	BOOST_FIXTURE_TEST_SUITE(when_created, when_created_)
		BOOST_AUTO_TEST_CASE(has_three_sides)
		{
			BOOST_CHECK_EQUAL(t.GetSide1(), 3);
			BOOST_CHECK_EQUAL(t.GetSide2(), 4);
			BOOST_CHECK_EQUAL(t.GetSide3(), 5);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()