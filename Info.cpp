#include "Info.h"

Info::Info() : name(""), age(0), gender(""), address("") {}

Info::Info(string name, int age, string gender, string address)
    : name(name), age(age), gender(gender), address(address) {}

void Info::setName(string n) { name = n; }
string Info::getName() const { return name; }

void Info::setAge(int a) { age = a; }
int Info::getAge() const { return age; }

void Info::setGender(string g) { gender = g; }
string Info::getGender() const { return gender; }

void Info::setAddress(string addr) { address = addr; }
string Info::getAddress() const { return address; }
