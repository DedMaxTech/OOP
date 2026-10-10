#include <gtest/gtest.h>
#include "class.h"

TEST(ClassTest, DefaultInit) {
    Creature creature;
    EXPECT_EQ("default_id", creature.get_id());
    EXPECT_EQ("Unknown", creature.get_name());
    EXPECT_EQ(100, creature.get_health());
}

TEST(ClassTest, EmptyInit) {
    Creature creature("","",1);
    EXPECT_EQ("fallback_id", creature.get_id());
    EXPECT_EQ("NoName", creature.get_name());
    EXPECT_EQ(1, creature.get_health());
}

TEST(ClassTest, CopyInit) {
    Creature creature("first","yes",100);
    Creature copy(creature);
    EXPECT_EQ("first_copy", copy.get_id());
    EXPECT_EQ("yes", copy.get_name());
    EXPECT_EQ(100, copy.get_health());
}

TEST(ClassTest, Eq) {
    Creature creature("first","yes",100);
    Creature creature2("second","no",2);
    creature = creature2;
    EXPECT_EQ("first", creature.get_id());
    EXPECT_EQ("no", creature.get_name());
    EXPECT_EQ(2, creature.get_health());
}

TEST(ClassTest, Setters) {
    Creature creature("first","yes",100);
    creature.set_name("new_name");
    creature.set_health(23);
    EXPECT_EQ("new_name", creature.get_name());
    EXPECT_EQ(23, creature.get_health());

    
}