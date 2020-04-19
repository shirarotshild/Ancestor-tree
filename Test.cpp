#include "doctest.h"
#include "FamilyTree.hpp"

using namespace family;
using namespace std;



TEST_CASE("Test find bad input"){
    Tree T ("Naomi"); 
	T.addFather("Naomi", "Benjamin") 
	 .addMother("Naomi", "Corinne") 
	 .addFather("Benjamin", "Henry")
	 .addMother("Benjamin", "Jacqueline");
	CHECK_THROWS_AS(T.find("uncle"), const exception&);
	CHECK_THROWS_AS(T.find("aunt"), const exception&);
	CHECK_THROWS_AS(T.find("nephew"), const exception&);
	CHECK_THROWS_AS(T.find("niece"), const exception&);
	CHECK_THROWS_AS(T.find("cousin"), const exception&);
	CHECK_THROWS_AS(T.find("daughter"), const exception&);
	CHECK_THROWS_AS(T.find("son"), const exception&); 
	CHECK_THROWS_AS(T.find("dog"), const exception&); 
	CHECK_THROWS_AS(T.find("cat"), const exception&); 

}

TEST_CASE("Test for small trees"){
	Tree T1("Naomi");
	T1.addFather("Naomi", "Benjamin") 
	 .addMother("Naomi", "Jacqueline");
	CHECK(T1.relation("Benjamin") == "father");
	CHECK(T1.relation("Jacqueline") == "mother");
	CHECK(T1.find("father") == "Benjamin");
	CHECK(T1.find("mother") == "Jacqueline");
	Tree T2("Shimon");
	T2.addFather("Shimon", "Mickael") 
	 .addMother("Shimon", "Agnes");
	CHECK(T2.relation("Mickael") == "father");
	CHECK(T2.relation("Agnes") == "mother");
	CHECK(T2.find("father") == "Mickael");
	CHECK(T2.find("mother") == "Agnes");
	Tree T3("Sarah");
	T3.addFather("Sarah", "Gilles") 
	 .addMother("Sarah", "Florence");
	CHECK(T3.relation("Gilles") == "father");
	CHECK(T3.relation("Florence") == "mother");
	CHECK(T3.find("father") == "Gilles");
	CHECK(T3.find("mother") == "Florence");
	Tree T4("Talya");
	T4.addFather("Talya", "Jacques") 
	 .addMother("Talya", "Gila");
	CHECK(T4.relation("Jacques") == "father");
	CHECK(T4.relation("Gila") == "mother");
	CHECK(T4.find("father") == "Jacques");
	CHECK(T4.find("mother") == "Gila");
}

TEST_CASE("Test name not found in current tree"){
    Tree T ("Naomi"); 
	T.addFather("Naomi", "Benjamin") 
	 .addMother("Naomi", "Corinne") 
	 .addFather("Benjamin", "Henry")
	 .addMother("Benjamin", "Jacqueline");
	CHECK_THROWS_AS(T.find("great-grandfather"), const exception&);
	CHECK_THROWS_AS(T.find("great-great-grandfather"), const exception&);
	CHECK_THROWS_AS(T.find("great-grandmother"), const exception&);
	CHECK_THROWS_AS(T.find("great-great-grandmother"), const exception&);
	T.remove("Corinne");
	T.remove("Benjamin");
	T.remove("Henry");
	T.remove("Jacqueline");
	CHECK_THROWS_AS(T.find("mother"), const exception&);
	CHECK_THROWS_AS(T.find("father"), const exception&);
	CHECK_THROWS_AS(T.find("grandmother"), const exception&);
	CHECK_THROWS_AS(T.find("grandfather"), const exception&);
}


TEST_CASE("Test relation not found"){
    Tree T ("Naomi"); 
	T.addFather("Naomi", "Benjamin") 
	 .addMother("Naomi", "Jacqueline") 
	 .addFather("Benjamin", "Henry")
	 .addMother("Benjamin", "Jacqueline")
	 .addFather("Henry", "Christophe")
	 .addMother("Henry", "Julia");
	CHECK(T.relation("jonny") == "unrelated");
	CHECK(T.relation("pablo") == "unrelated");
	CHECK(T.relation("mick") == "unrelated");
	CHECK(T.relation("ben") == "unrelated");
	CHECK(T.relation("brad") == "unrelated");
	CHECK(T.relation("penny") == "unrelated");
	CHECK(T.relation("ken") == "unrelated");
	CHECK(T.relation("tom") == "unrelated");
	CHECK(T.relation("erick") == "unrelated");
	CHECK(T.relation("chris") == "unrelated");
	CHECK(T.relation("gavin") == "unrelated");
	CHECK(T.relation("kyle") == "unrelated");
	CHECK(T.relation("troy") == "unrelated");
	CHECK(T.relation("evan") == "unrelated");
	CHECK(T.relation("paris") == "unrelated");
	CHECK(T.relation("ben") == "unrelated");
	CHECK(T.relation("fanny") == "unrelated");
	CHECK(T.relation("yolande") == "unrelated");
	CHECK(T.relation("roger") == "unrelated");
	CHECK(T.relation("walter") == "unrelated");
	CHECK(T.relation("quentin") == "unrelated");


} 

TEST_CASE("Test with large family tree"){
    Tree T ("Naomi"); 
	T.addFather("Naomi", "Benjamin") 
	 .addMother("Naomi", "Corinne") 
	 .addFather("Benjamin", "Henry")
	 .addMother("Benjamin", "Jacqueline")
	 .addFather("Corinne", "Nissim")
	 .addMother("Corinne", "Gloria")
	 .addFather("Henry", "Christophe")
	 .addMother("Henry", "Madeleine")
	 .addFather("Christophe", "Jacques")
	 .addMother("Christophe", "Julia");
	 T.display();
	CHECK(T.relation("Benjamin") == "father");
	CHECK(T.relation("Corinne") == "mother");
	CHECK(T.relation("Henry") == "grandfather");
	CHECK(T.relation("Jacqueline") == "grandmother");
	CHECK(T.relation("Nissim") == "grandfather");
	CHECK(T.relation("Gloria") == "grandmother");
	CHECK(T.relation("Christophe") == "great-grandfather");
	CHECK(T.relation("Madeleine") == "great-grandmother");
	CHECK(T.relation("Jacques") == "great-great-grandfather");
	CHECK(T.relation("Julia") == "great-great-grandmother");
    CHECK(T.relation("Naomi") == "me"); 
}


TEST_CASE("Test tree with leaves removed"){
    Tree T ("Naomi"); 
	T.addFather("Naomi", "Benjamin") 
	 .addMother("Naomi", "Jacqueline") 
	 .addFather("Benjamin", "Henry")
	 .addMother("Benjamin", "Jacqueline")
	 .addFather("Henry", "Christophe")
	 .addFather("Christophe", "Jacques")
	 .addFather("Jacqueline", "Nissim")
	 .addMother("Jacqueline", "Gloria")
	 .addFather("Nissim", "David")
	 .addFather("David", "Yacov");

	T.remove("Jacques");
	T.remove("Christophe");
	T.remove("Jacqueline");
	T.remove("Henry");
	T.remove("Jacqueline");
	T.remove("Benjamin");
	T.remove("Yacov");
	T.remove("David");
	T.remove("Nissim");
	T.remove("Gloria");
	
	CHECK_THROWS(T.find("Jacques")); 
	CHECK_THROWS(T.find("Christophe")); 
	CHECK_THROWS(T.find("Jacqueline")); 
	CHECK_THROWS(T.find("Yacov")); 
	CHECK_THROWS(T.find("David")); 
	CHECK_THROWS(T.find("Nissim")); 
	CHECK_THROWS(T.find("Gloria")); 
	CHECK_THROWS(T.find("Jacqueline")); 
	CHECK_THROWS(T.find("Henry")); 
	CHECK_THROWS(T.find("Benjamin")); 
}


TEST_CASE("Test addition of leaves after removing"){
    Tree T ("Naomi"); 
	T.addFather("Naomi", "Benjamin") 
	 .addMother("Naomi", "Corinne") 
	 .addFather("Benjamin", "Henry")
	 .addMother("Benjamin", "Jacqueline")
	 .addFather("Henry", "Jacques")
	 .addMother("Henry", "Lucille")
	 .addFather("Jacques", "Lucien");
	T.remove("Lucien");
	T.remove("Jacques");
	T.remove("Jacqueline");
	T.remove("Henry");
	T.remove("Corinne");
	T.remove("Benjamin");
	T.addFather("Naomi", "Benjamin") 
	 .addMother("Naomi", "Corinne") 
	 .addFather("Benjamin", "Henry")
	 .addMother("Benjamin", "Jacqueline")
	 .addFather("Henry", "Jacques")
	 .addMother("Henry", "Lucille")
	 .addFather("Jacques", "Lucien");

	CHECK(T.relation("Benjamin") == "father");
	CHECK(T.relation("Corinne") == "mother");
	CHECK(T.relation("Henry") == "grandfather");
	CHECK(T.relation("Jacqueline") == "grandmother");
	CHECK(T.relation("Jacques") == "great-grandfather");
	CHECK(T.relation("Lucille") == "great-grandmother");
	CHECK(T.relation("Lucien") == "great-great-grandfather");
	CHECK(T.relation("Naomi") == "me"); 
}


TEST_CASE("Test unordered removal"){
    Tree T ("Naomi"); 
	T.addFather("Naomi", "Benjamin") 
	 .addMother("Naomi", "Corinne") 
	 .addFather("Benjamin", "Henry")
	 .addMother("Benjamin", "Jacqueline")
	 .addFather("Henry", "Jacques");
	 T.remove("Benjamin");

	CHECK(T.relation("Benjamin") == "unrelated");
	CHECK(T.relation("Corinne") == "mother");
	CHECK(T.relation("Henry") == "unrelated");
	CHECK(T.relation("Jacqueline") == "unrelated");
	CHECK(T.relation("Jacques") == "unrelated");
	CHECK(T.relation("Naomi") == "me");

	Tree T1 ("Shimon"); 
	T1.addFather("Shimon", "Mickael") 
	 .addMother("Shimon", "Agnes") 
	 .addFather("Mickael", "Roy")
	 .addMother("Mickael", "Marcel")
	 .addFather("Roy", "Samuel");
	 T1.remove("Mickael");

	CHECK(T1.relation("Mickael") == "unrelated");
	CHECK(T1.relation("Agnes") == "mother");
	CHECK(T1.relation("Roy") == "unrelated");
	CHECK(T1.relation("Marcel") == "unrelated");
	CHECK(T1.relation("Samuel") == "unrelated");
	CHECK(T1.relation("Shimon") == "me");
}



TEST_CASE("Test unordered removal"){
    Tree T ("Naomi"); 
	T.addFather("Naomi", "Benjamin") 
	 .addMother("Naomi", "Corinne") 
	 .addFather("Corinne", "Nissim")
	 .addMother("Corinne", "Gloria")
	 .addFather("Benjamin", "Henry")
	 .addMother("Benjamin", "Jacqueline")
	 .addFather("Henry", "Jacques")
	 .addFather("Jacques", "Lucien");
	T.remove("Benjamin");

	CHECK(T.relation("Benjamin") == "unrelated");
	CHECK(T.relation("Corinne") == "mother");
	CHECK(T.relation("Henry") == "unrelated");
	CHECK(T.relation("Nissim") == "grandfather");
	CHECK(T.relation("Gloria") == "grandmother");
	CHECK(T.relation("Jacqueline") == "unrelated");
	CHECK(T.relation("Jacques") == "unrelated");
	CHECK(T.relation("Lucien") == "unrelated");
	CHECK(T.relation("Naomi") == "me");
	CHECK(T.relation("Benjamin") == "unrelated");
	CHECK(T.relation("Corinne") == "mother");
	CHECK(T.relation("Henry") == "unrelated");
	CHECK(T.relation("Nissim") == "grandfather");
	CHECK(T.relation("Gloria") == "grandmother");
	CHECK(T.relation("Jacqueline") == "unrelated");
	CHECK(T.relation("Jacques") == "unrelated");
	CHECK(T.relation("Lucien") == "unrelated");
	CHECK(T.relation("Naomi") == "me");
}


TEST_CASE("Test find name in current tree"){
    Tree T ("Naomi"); 
	T.addFather("Naomi", "Benjamin") 
	 .addMother("Naomi", "Corinne") 
	 .addFather("Benjamin", "Henry")
	 .addMother("Benjamin", "Jacqueline")
	 .addFather("Henry", "Jacques")
	 .addMother("Henry", "Lucille")
	 .addFather("Jacques", "Lucien")
	 .addMother("Jacques", "Marguerite");

	CHECK(T.find("father") == "Benjamin");
	CHECK(T.find("mother") == "Corinne");
	CHECK(T.find("grandfather") == "Henry");
	CHECK(T.find("grandmother") == "Jacqueline");
	CHECK(T.find("great-grandfather") == "Jacques");
	CHECK(T.find("great-grandmother") == "Lucille");
	CHECK(T.find("great-great-grandfather") == "Lucien");
	CHECK(T.find("great-great-grandmother") == "Marguerite");
	CHECK(T.find("me") == "Naomi"); 
}





TEST_CASE("Test relation and find being inverse"){
    Tree T ("Naomi"); 
	T.addFather("Naomi", "Benjamin") 
	 .addMother("Naomi", "Corinne") 
	 .addFather("Benjamin", "Henry")
	 .addMother("Benjamin", "Jacqueline")
	 .addFather("Henry", "Jacques")
	 .addFather("Jacques", "Lucien");
	CHECK(T.relation(T.find("father")) == "father");
	CHECK(T.relation(T.find("mother")) == "mother");
	CHECK(T.relation(T.find("grandfather")) == "grandfather");
	CHECK(T.relation(T.find("grandmother")) == "grandmother");
	CHECK(T.relation(T.find("great-grandfather")) == "great-grandfather");
	CHECK(T.relation(T.find("great-great-grandfather")) == "great-great-grandfather");
	CHECK(T.find(T.relation("Naomi")) == "Naomi");
	CHECK(T.find(T.relation("Corinne")) == "Corinne");
	CHECK(T.find(T.relation("Benjamin")) == "Benjamin");
	CHECK(T.find(T.relation("Henry")) == "Henry");
	CHECK(T.find(T.relation("Jacques")) == "Jacques");
	CHECK(T.find(T.relation("Lucien")) == "Lucien");
}
© 2020 GitHub, Inc.
