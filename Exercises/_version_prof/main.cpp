///
/// Ce projet utilise quelques librairies disponibles sur Vcpkg et permet entre autre d'en tester le bon fonctionnement.
///


#include <cstddef>
#include <cstdint>

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <span>

#include <cppitertools/range.hpp>
#include <cppitertools/enumerate.hpp>
#include <cppitertools/zip.hpp>

#include "Employee.hpp"
#include "Company.hpp"
#include "tuples.hpp"

using namespace std;
using namespace iter;


void runEmployeeExample() {
	Employee marcel;
	cout << marcel.getName() << "\n"
	     << marcel.getSalary() << "\n";
	Employee marcelGang[3];
	const Employee marcel1 = Employee("Marcel");
	cout << marcel1.getName() << "\n"
	     << marcel1.getSalary() << "\n";
	Employee marcel2("Marcel", 50'000);
	Employee marcel3{"Marcel", 50'000};
	//Employee marcel4 = Employee(); // Erreur si ctor par défaut pas défini
	Employee marcel5; // Erreur si ctor par défaut pas défini
	cout << "- - - - - - - - - - -" << "\n";
}

void runCompanyExample() {
	Employee* firstEmployees[2] = {
		new Employee("Emily Williams", 50'000),
		new Employee("Richard Trottier", 40'000)
	};
	cout << "- - - - - -" << "\n";
	Company stonks("Stonks LLC", "chosson", 42'000, firstEmployees);
	cout << "- - - - - -" << "\n";
	stonks.print();
	cout << "- - - - - -" << "\n";
	stonks.getPresident().setSalary(69'420);
	stonks.addEmployee("Foo", 69);
	stonks.addEmployee("Bar", 42);
	stonks.addEmployee("Qux", 9000);
	stonks.addEmployee("Spam", 1337);
	stonks.addEmployee("Eggs", 0xDEAD);
	stonks.print();
	cout << "- - - - - - - - - - -" << "\n";
}

void runTuplesExample() {
	{
		vector<int> foo = {1, 3, -5, 10, 42, 69};
		MinMax minmax = findMinMax_v1(foo);
		auto&& [min, max] = findMinMax(foo);
		cout << "min=" << minmax.min << ", max=" << minmax.max << "\n"
			 << "min=" << min << ", max=" << max << "\n";
	}
	{
		vector<int> bar = {1, 2, 3, 4, 5, 6};
		auto [min, max, avg] = findMinMaxAvg(bar);
		cout << "min=" << min << ", max=" << max << ", avg=" << avg << "\n";
	}
}


int main() {
	runEmployeeExample();
	cout << "\n\n";
	runCompanyExample();
	cout << "\n\n";
	runTuplesExample();
}

