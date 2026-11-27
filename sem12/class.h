#pragma once
/** @file class.h
 * @brief Наследование и полиморфизм существ.
 */
#include <iostream>
#include <string>

/// @brief Абстрактное существо.
class Creature {
private:
    const std::string id;
    std::string name;
    int health;
    int* arr;

public:
    /// @brief Создаёт Unknown со здоровьем 100.
    Creature();
    /// @param new_id ID; пустой заменяется на fallback_id.
    /// @param new_name Имя; пустое заменяется на NoName.
    /// @param new_health Здоровье.
    Creature(const std::string& new_id, const std::string& new_name, int new_health);
    /// @brief Копирует данные; к ID добавляет _copy.
    /// @param other Источник копии.
    Creature(const Creature& other);
    /// @brief Освобождает массив.
    /// @note Допускает удаление наследников через Creature*.
    virtual ~Creature();
    /// @brief Копирует данные, сохраняя ID получателя.
    /// @param other Источник данных.
    /// @return Ссылка на текущий объект.
    Creature& operator=(const Creature& other);

    /// @return Неизменяемый ID.
    const std::string& get_id() const;
    /// @return Имя.
    const std::string& get_name() const;
    /// @return Здоровье.
    int get_health() const;

    /// @param new_name Новое имя; пустое заменяется на NoName.
    void set_name(const std::string& new_name);
    /// @param new_health Новое здоровье.
    void set_health(int new_health);

    /// @brief Атака, определяемая наследником.
    virtual void fight() const = 0;
    /// @brief Выводит имя и здоровье.
    /// @note Невиртуальный: вызов зависит от статического типа.
    void info() const;
};

/// @brief Обычное существо.
class CommonCreature : public Creature {
public:
    /// @param id ID.
    /// @param name Имя.
    /// @param health Здоровье.
    CommonCreature(const std::string& id, const std::string& name, int health);
    
    /// @brief Сообщает об обычной атаке.
    void fight() const override;
    /// @brief Выводит имя и здоровье.
    /// @see Creature::info
    void info() const;
};

/// @brief Лучник.
class Archer : public CommonCreature {
private:
    int arrows_quantity;

public:
    static constexpr int max_arrows = 30; ///< Предел запаса стрел.

    /// @param id ID.
    /// @param name Имя.
    /// @param health Здоровье.
    /// @param arrows Стрелы; значение ограничивается диапазоном [0, max_arrows].
    Archer(const std::string& id, const std::string& name, int health, int arrows);

    /// @brief Выводит запас стрел.
    void show_arrows_quantity() const;
    /// @brief Сообщает о выстреле или отсутствии стрел.
    /// @note Стрелы не расходуются.
    void shoot() const;
    
    /// @brief Прицеливается и вызывает shoot().
    void fight() const override;
    /// @brief Выводит имя и запас стрел.
    void info() const;
};

/// @brief Летающий лучник.
class FlyingArcher : public Archer {
private:
    double flight_altitude;

public:
    /// @param id ID.
    /// @param name Имя.
    /// @param health Здоровье.
    /// @param arrows Стрелы; значение ограничивается диапазоном [0, max_arrows].
    /// @param altitude Высота в метрах; отрицательная заменяется нулём.
    FlyingArcher(const std::string& id, const std::string& name, int health, int arrows, double altitude);

    /// @return Высота полёта в метрах.
    double get_altitude() const;
    /// @param altitude Высота в метрах; отрицательная заменяется нулём.
    void set_altitude(double altitude);
    /// @brief Сообщает о полёте и высоте.
    void fly() const;
    /// @brief Выводит все характеристики.
    void show_status() const;

    /// @brief Атакует с воздуха через shoot().
    void fight() const override;
    /// @brief Выводит имя и высоту.
    void info() const;
};
