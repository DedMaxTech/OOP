#include "academy.h"

void processAcademyRequest(const MagicAcademy& academy, const GraduateInfo& data, bool fullReport) {
    academy.graduateAndReport(data, fullReport);
}

int main() {
    setlocale(LC_ALL, "Russian");

    CommonAcademy commonSchool;
    ArcheryAcademy archerSchool;
    SkyArcheryAcademy skySchool;

    GraduateInfo recruit1{"G-01", "Goblin", 100, 145.5, 48.0, "Coat"};
    GraduateInfo recruit2{"A-12", "Legolas", 150, 185.0, 72.5, "Elf boots", 25};
    GraduateInfo recruit3{"V-99", "Valk", 200, 178.0, 65.0, "Wings", 30, 500.0};

    processAcademyRequest(commonSchool, recruit1, false);
    processAcademyRequest(archerSchool, recruit2, true);
    processAcademyRequest(skySchool, recruit3, true);

    return 0;
}
