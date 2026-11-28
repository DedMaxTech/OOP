#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "class.h"

struct GraduateInfo {
    std::string id;
    std::string name;
    int health;
    double height;
    double weight;
    std::string outfit;
    int arrows = 0;
    double altitude = 0;
};

class MagicAcademy {
public:
    virtual ~MagicAcademy() = default;

    virtual std::unique_ptr<Creature> createCreature(const GraduateInfo& info) const = 0;

    virtual std::string getAcademySpecialization() const = 0;

    void graduateAndReport(const GraduateInfo& info, bool showExtendedInfo = true) const {
        std::cout << "=== Academy: " << getAcademySpecialization() << " ===\n";
        
        std::unique_ptr<Creature> creature = createCreature(info);
        
        std::cout << "Graduated creature: " << creature->get_name() 
                  << " (ID: " << creature->get_id() << ")\n";

        if (showExtendedInfo) {
            std::cout << "[Secret info] Height: " << info.height << " m, "
                      << "Weight: " << info.weight << " rg, "
                      << "Items: " << info.outfit << "\n";
        }

        creature->info();
        creature->fight();
        std::cout << "==========================================\n\n";
    }
};

class CommonAcademy : public MagicAcademy {
public:
    std::unique_ptr<Creature> createCreature(const GraduateInfo& info) const override {
        return std::make_unique<CommonCreature>(info.id, info.name, info.health);
    }

    std::string getAcademySpecialization() const override {
        return "Survival academy";
    }
};

class ArcheryAcademy : public MagicAcademy {
public:
    std::unique_ptr<Creature> createCreature(const GraduateInfo& info) const override {
        return std::make_unique<Archer>(info.id, info.name, info.health, info.arrows);
    }

    std::string getAcademySpecialization() const override {
        return "Archers academy";
    }
};

class SkyArcheryAcademy : public MagicAcademy {
public:
    std::unique_ptr<Creature> createCreature(const GraduateInfo& info) const override {
        return std::make_unique<FlyingArcher>(info.id, info.name, info.health, info.arrows, info.altitude);
    }

    std::string getAcademySpecialization() const override {
        return "High flying archers academy";
    }
};
