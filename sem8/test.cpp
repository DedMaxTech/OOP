#include <gtest/gtest.h>
#include <sstream>
#include <utility>
#include "class.h"

class ClassTest : public testing::Test {
protected:
    Creature<> creature{"first", "Hero", 100};

    // void SetUp() override {
    // }

    // void TearDown() override {
    // }
};

TEST_F(ClassTest, DefaultInit) {
    Creature<> obj;
    EXPECT_EQ("default_id", obj.get_id());
    EXPECT_EQ("Unknown", obj.get_name());
    EXPECT_EQ(100, obj.get_health());
}

TEST_F(ClassTest, EmptyInit) {
    Creature<> obj("", "", 0);
    EXPECT_EQ("fallback_id", obj.get_id());
    EXPECT_EQ("NoName", obj.get_name());
    EXPECT_EQ(0, obj.get_health());
}

TEST_F(ClassTest, CopyInit) {
    Creature<> copy(creature);
    EXPECT_EQ("first_copy", copy.get_id());
    EXPECT_EQ("Hero", copy.get_name());
    EXPECT_EQ(100, copy.get_health());
    copy.set_name("Copy");
    EXPECT_EQ("Hero", creature.get_name());
}

TEST_F(ClassTest, CopyAssign) {
    Creature<> obj("second", "Other", 1);
    obj = creature;
    EXPECT_EQ("second", obj.get_id());
    EXPECT_EQ("Hero", obj.get_name());
    EXPECT_EQ(100, obj.get_health());
    obj.set_health(20);
    EXPECT_EQ(100, creature.get_health());
}

TEST_F(ClassTest, MoveInit) {
    Creature<> obj(std::move(creature));
    EXPECT_EQ("first", obj.get_id());
    EXPECT_EQ("Hero", obj.get_name());
    EXPECT_EQ(100, obj.get_health());
    creature.set_name("New hero");
    EXPECT_EQ("New hero", creature.get_name());
}

TEST_F(ClassTest, MoveAssign) {
    Creature<> obj("second", "Other", 1);
    obj = std::move(creature);
    EXPECT_EQ("second", obj.get_id());
    EXPECT_EQ("Hero", obj.get_name());
    EXPECT_EQ(100, obj.get_health());
}

TEST_F(ClassTest, Setters) {
    creature.set_name("New name");
    creature.set_health(23);
    EXPECT_EQ("New name", creature.get_name());
    EXPECT_EQ(23, creature.get_health());
    creature.set_name("");
    EXPECT_EQ("NoName", creature.get_name());
}

TEST_F(ClassTest, InvalidHealth) {
    EXPECT_THROW(Creature<>("bad", "Bad", -1), std::invalid_argument);
    EXPECT_THROW(creature.set_health(-1), std::invalid_argument);
    EXPECT_EQ(100, creature.get_health());
}

TEST_F(ClassTest, StreamOperators) {
    std::istringstream input("Mage 75");
    input >> creature;
    EXPECT_FALSE(input.fail());
    EXPECT_EQ("Mage", creature.get_name());
    EXPECT_EQ(75, creature.get_health());

    std::istringstream invalid("Other abc");
    invalid >> creature;
    EXPECT_TRUE(invalid.fail());
    EXPECT_EQ("Mage", creature.get_name());
    EXPECT_EQ(75, creature.get_health());

    std::ostringstream output;
    output << creature;
    EXPECT_NE(std::string::npos, output.str().find("Creature, count="));
    EXPECT_NE(std::string::npos, output.str().find("uid="));
    EXPECT_NE(std::string::npos, output.str().find("id=first, name=Mage, health=75"));
}

TEST_F(ClassTest, DoubleHealth) {
    Creature<double> mage("mage", "Mage", 75.5);
    EXPECT_DOUBLE_EQ(75.5, mage.get_health());
    mage.set_health(80.25);
    EXPECT_DOUBLE_EQ(80.25, mage.get_health());
}
