#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;
#include <string>
using namespace std;


TEST_CASE("Test replacement of Yosef Tree") {
	 family::Tree Yosef ("Yosef");
	Yosef.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
    .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	.addFather("Yaakov", "Isaac")
	.addMother("Yaakov", "Rivka")
	.addFather("Isaac", "Avraham")
	.addFather("Avraham", "Terah");
//	CHECK_EQUAL (Yosef.relation("Yaakov") , "father")
     
	
}
