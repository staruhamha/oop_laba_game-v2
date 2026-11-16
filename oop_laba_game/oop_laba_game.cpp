#include <iostream>
using namespace std;

#include "GameField.h"
#include "GameFieldIterator.h"
#include "Factories.h"

#include <ctime>
#include <cstdlib>
#include <utility>

#include <vector>
#include <string>

#include "Tests.h"

#include "Base.h"
#include "TerrainMap.h"
#include "TerrainTypes.h"
#include "GameController.h"

void clear() {
    system("cls");
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(nullptr)));

    AssaultFactory assaultFactory;
    MarksmanFactory marksmanFactory;
    SpecialistFactory specialistFactory;
    JetpackFactory jetpackFactory;


    int choice;

    while (true) {

        cout << "1. Битва Soldier против Heavy\n";
        cout << "2. Soldier и Pyro против Heavy\n";
        cout << "3. Heavy против Soldier (ответная атака)\n";
        cout << "4. Перемещение юнитов и сражение\n";

        cout << "5. Модульное тестирование\n";
        cout << "6. Демонстрация третьего этапа\n";
        cout << "7. Демонстрация нейтральных объектов (четвёртый этап)\n";
        cout << "8. Демонстрация создания базы и юнитов (пятый этап)\n";
        cout << "9. Демонстрация перемещения по разным типам ландшафта\n";
        cout << "10. Демонстрация взаимодействия с нейтральными объектами (пятый этап)\n";
        cout << "11. Демонстрация уничтожения юнита и уведомления базы (пятый этап)\n";

        cout << "0. Выход\n";
    

        cin >> choice;
        switch (choice) {
        
        case 0: {
            return 0;
        }
        case 1: {
            clear();
            cout << "Soldier против Heavy\n";
            GameField battleField(3, 3);

            vector<string> soldier = { "Soldier" };
            vector<string> heavy = { "Heavy" };

            battleField.fill(assaultFactory, soldier);
            battleField.fill(assaultFactory, heavy);

            cout << "Игровое поле:\n";
            battleField.printField();

            Unit* soldierUnit = battleField.getUnit(0);
            Unit* heavyUnit = battleField.getUnit(1);

            cout << "\nДо атаки:\n";
            cout << "Heavy\n";
            cout << "Здоровье: " << heavyUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << heavyUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nSoldier атакует Heavy\n";

            soldierUnit->attack(*heavyUnit);

            cout << "\nПосле атаки:\n";
            cout << "Heavy\n";
            cout << "Здоровье: " << heavyUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << heavyUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nВыход - Enter";
            cin.ignore();
            cin.get();
            clear();
            break;
        }
        case 2: {
            clear();
            cout << "Soldier и Pyro против Heavy\n";
            GameField battleField(3, 3);

            
            vector<string> heavy = { "Heavy" };

            vector<string> soldier = { "Soldier" };
            vector<string> pyro = { "Pyro" };

            battleField.fill(assaultFactory, soldier);
            battleField.fill(specialistFactory, pyro);

            battleField.fill(assaultFactory, heavy);

            cout << "Игровое поле:\n";
            battleField.printField();

            Unit* soldierUnit = battleField.getUnit(0);
            Unit* pyroUnit = battleField.getUnit(1);
            Unit* heavyUnit = battleField.getUnit(2);

            cout << "\nДо атаки:\n";
            cout << "Heavy\n";
            cout << "Здоровье: " << heavyUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << heavyUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nSoldier атакует Heavy\n";
            soldierUnit->attack(*heavyUnit);

            cout << "\nПосле атаки Soldier:\n";
            cout << "Здоровье: " << heavyUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << heavyUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nPyro атакует Heavy\n";
            pyroUnit->attack(*heavyUnit);

            cout << "\nПосле атаки Pyro:\n";
            cout << "Здоровье: " << heavyUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << heavyUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nВыход - Enter";
            cin.ignore();
            cin.get();
            clear();
            break;
        }
        case 3: {
            clear();
            cout << "Heavy против Soldier (ответная атака)\n";
            GameField battleField(3, 3);

            vector<string> soldier = { "Soldier" };
            vector<string> heavy = { "Heavy" };

            battleField.fill(assaultFactory, soldier);
            battleField.fill(assaultFactory, heavy);

            cout << "Игровое поле:\n";
            battleField.printField();

            Unit* soldierUnit = battleField.getUnit(0);
            Unit* heavyUnit = battleField.getUnit(1);

            cout << "\nДо атаки:\n";
            cout << "Soldier\n";
            cout << "Здоровье: " << soldierUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << soldierUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nHeavy атакует Soldier\n";
            heavyUnit->attack(*soldierUnit);

            cout << "\nПосле атаки Heavy:\n";
            cout << "Soldier\n";
            cout << "Здоровье: " << soldierUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << soldierUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nSoldier атакует Heavy\n";
            soldierUnit->attack(*heavyUnit);

            cout << "\nПосле ответной атаки Soldier:\n";
            cout << "Heavy\n";
            cout << "Здоровье: " << heavyUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << heavyUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nВыход - Enter";
            cin.ignore();
            cin.get();
            clear();
            break;
        }
        case 4: {
            clear();
            cout << "Перемещение юнитов и сражение\n";

            GameField battleField(3, 3);

            vector<string> soldier = { "Soldier" };
            vector<string> heavy = { "Heavy" };

            battleField.fill(assaultFactory, soldier);
            battleField.fill(assaultFactory, heavy);

            Unit* soldierUnit = battleField.getUnit(0);
            Unit* heavyUnit = battleField.getUnit(1);

            cout << "Начальное расположение:\n";
            battleField.printField();

            soldierUnit->move(1, 0);
            heavyUnit->move(0, 1);

            cout << "\nПосле перемещения:\n";
            battleField.printField();

            cout << "\nДо атаки:\n";
            cout << "Soldier health: " << soldierUnit->getHealth().getCurrentHealth() << '\n';
            cout << "Heavy health: " << heavyUnit->getHealth().getCurrentHealth() << '\n';
            cout << "Heavy armor: " << heavyUnit->getArmor().getCurrentArmor() << '\n';

            soldierUnit->attack(*heavyUnit);

            cout << "\nПосле атаки Soldier:\n";
            cout << "Soldier health: " << soldierUnit->getHealth().getCurrentHealth() << '\n';
            cout << "Heavy health: " << heavyUnit->getHealth().getCurrentHealth() << '\n';
            cout << "Heavy armor: " << heavyUnit->getArmor().getCurrentArmor() << '\n';

            cout << "\nВыход - Enter";
            cin.ignore();
            cin.get();
            clear();
            break;
        }
        case 5: {
            clear();
            runTests();

            cout << "\nНажмите Enter для продолжения";
            cin.ignore();
            cin.get();
            clear();
            break;
        }
        case 6: {
            clear();
            cout << "Демонстрация третьего этапа\n";
            Base base(1000, 1, 0, 500);
            TerrainMap terrainMap(3, 3);
            terrainMap.setTerrain(1, 0, make_unique<Mountains>());
            shared_ptr<Unit> soldier = base.createUnit(0, 0, "Soldier");
            if (soldier == nullptr) {
                cout << "Не удалось создать Soldier\n";
                break;
            }
            cout << "Soldier создан базой.\n";

            Terrain* terrain = terrainMap.getTerrain(1, 0);

            cout << "\nSoldier пытается пройти через горы:\n";

            if (terrain->isPassable(soldier->getTypeInfo().type)) {
                soldier->move(1, 0);
                cout << "Soldier переместился.\n";
            }
            else {
                cout << "Soldier не может пройти через горы.\n";
            }
            cout << "\nНаносим Soldier смертельный урон:\n";
            soldier->takeDamage(10000);
            base.removeUnit(soldier->getId());
            shared_ptr<Unit> jetpack = base.createUnit(1, 0, "JetpackTrooper");

            if (jetpack == nullptr) {
                cout << "Не удалось создать JetpackTrooper\n";
                break;
            }

            cout << "\nJetpackTrooper создан базой.\n";

            cout << "\nJetpackTrooper пытается пройти через горы:\n";

            if (terrain->isPassable(jetpack->getTypeInfo().type)) {
                jetpack->move(1, 0);
                cout << "JetpackTrooper переместился.\n";
            }
            else {
                cout << "JetpackTrooper не может пройти.\n";
            }

            cout << "\nДополнительные характеристики ландшафта:\n";
            cout << "Модификатор скорости: "
                << terrain->getSpeedModifier(jetpack->getTypeInfo().type) << "\n";

            cout << "Бонус защиты: "
                << terrain->getDefenseBonus(jetpack->getTypeInfo().type) << "\n";
            cout << "\nВыход - Enter";
            cin.ignore();
            cin.get();
            clear();
            break;
        }
        case 7: {
            clear();
            cout << "Демонстрация четвёртого этапа\n";

            Base base(1000, 5, 0, 100);

            TerrainMap terrainMap(3, 3);

            shared_ptr<Unit> soldier = base.createUnit(0, 0, "Soldier");
            shared_ptr<Unit> marksman = base.createUnit(1, 0, "Sniper");

            if (soldier == nullptr || marksman == nullptr) {
                cout << "Не удалось создать юнитов\n";
                break;
            }

            terrainMap.setNeutralObjectAt(0, 0, make_shared<SupplyCrate>(base, 50));
            terrainMap.setNeutralObjectAt(1, 0, make_shared<Mine>(20));
            terrainMap.setNeutralObjectAt(2, 0, make_shared<PowerCrate>(15));
            terrainMap.setNeutralObjectAt(0, 1, make_shared<Dispenser>(30));
            terrainMap.setNeutralObjectAt(1, 1, make_shared<PowerCrate>(10));

            cout << "\nSupplyCrate: получение ресурсов\n";
            NeutralObject* object = terrainMap.getNeutralObjectAt(0, 0);
            if (object != nullptr) {
                SupplyCrate* crate = dynamic_cast<SupplyCrate*>(object);
                if (crate != nullptr) {
                    *crate + *soldier;
                }
            }
            cout << "Ресурсы базы: " << base.getResources() << "\n";

            cout << "\nMine: нанесение урона\n";
            object = terrainMap.getNeutralObjectAt(1, 0);
            if (object != nullptr) {
                Mine* mine = dynamic_cast<Mine*>(object);
                if (mine != nullptr) {
                    *mine - *soldier;
                }
            }
            cout << "Здоровье Soldier: " << soldier->getHealth().getCurrentHealth() << "\n";

            cout << "\nPowerCrate: усиление атаки Soldier\n";
            object = terrainMap.getNeutralObjectAt(2, 0);
            if (object != nullptr) {
                PowerCrate* altar = dynamic_cast<PowerCrate*>(object);
                if (altar != nullptr) {
                    *altar** soldier;
                }
            }
            cout << "Атака Soldier: " << soldier->getAttack().getDamage() << "\n";

            cout << "\nDispenser: восстановление здоровья Soldier\n";
            object = terrainMap.getNeutralObjectAt(0, 1);
            if (object != nullptr) {
                Dispenser* dispenser = dynamic_cast<Dispenser*>(object);
                if (dispenser != nullptr) {
                    *dispenser / *soldier;
                }
            }
            cout << "Здоровье Soldier: " << soldier->getHealth().getCurrentHealth() << "\n";

            cout << "\nPowerCrate: увеличение маны Marksman\n";
            object = terrainMap.getNeutralObjectAt(1, 1);
            if (object != nullptr) {
                PowerCrate* altar = dynamic_cast<PowerCrate*>(object);
                if (altar != nullptr) {
                    *altar** marksman;
                }
            }
            cout << "Мана Marksman: " << marksman->getMana() << "\n";

            cout << "\nВыход - Enter";
            cin.ignore();
            cin.get();
            clear();
            break;
        }
        case 8: {
            clear();
            cout << "Демонстрация создания базы и юнитов (пятый этап)\n";

            GameController controller(1000, 5, 0, 100, 5, 5);

            controller.getTerrainMap().setTerrain(0, 0, make_unique<Plains>());
            controller.getTerrainMap().setTerrain(1, 0, make_unique<Forest>());
            controller.getTerrainMap().setTerrain(2, 0, make_unique<Swamp>());
            controller.getTerrainMap().setTerrain(3, 0, make_unique<Mountains>());

            shared_ptr<Unit> soldier = controller.createUnit(assaultFactory, 0, 0, "Soldier");
            shared_ptr<Unit> sniper = controller.createUnit(marksmanFactory, 1, 0, "Sniper");
            shared_ptr<Unit> pyro = controller.createUnit(specialistFactory, 2, 0, "Pyro");
            shared_ptr<Unit> jetpack = controller.createUnit(jetpackFactory, 3, 0, "JetpackTrooper");

            cout << "\nСоздание юнитов:\n";

            if (soldier != nullptr) {
                cout << soldier->getType() << " создан. ID: " << soldier->getId()
                    << ", координаты: (" << soldier->getX() << ", " << soldier->getY() << ")\n";
            }

            if (sniper != nullptr) {
                cout << sniper->getType() << " создан. ID: " << sniper->getId()
                    << ", координаты: (" << sniper->getX() << ", " << sniper->getY() << ")\n";
            }

            if (pyro != nullptr) {
                cout << pyro->getType() << " создан. ID: " << pyro->getId()
                    << ", координаты: (" << pyro->getX() << ", " << pyro->getY() << ")\n";
            }

            if (jetpack != nullptr) {
                cout << jetpack->getType() << " создан. ID: " << jetpack->getId()
                    << ", координаты: (" << jetpack->getX() << ", " << jetpack->getY() << ")\n";
            }

            cout << "\nНачальные характеристики базы:\n";
            cout << "Здоровье: " << controller.getBase().getHealth() << "\n";
            cout << "Ресурсы: " << controller.getBase().getResources() << "\n";
            cout << "Максимальное количество юнитов: " << controller.getBase().getMaxUnits() << "\n";

            cout << "\nВыход - Enter";
            cin.ignore();
            cin.get();
            clear();
            break;
        }
        case 9: {
            clear();
            cout << "Демонстрация перемещения по разным типам ландшафта\n";

            GameController controller(1000, 5, 0, 100, 5, 2);

            controller.getTerrainMap().setTerrain(0, 0, make_unique<Plains>());
            controller.getTerrainMap().setTerrain(1, 0, make_unique<Forest>());
            controller.getTerrainMap().setTerrain(2, 0, make_unique<Swamp>());
            controller.getTerrainMap().setTerrain(3, 0, make_unique<Mountains>());

            controller.getTerrainMap().setTerrain(0, 1, make_unique<Plains>());
            controller.getTerrainMap().setTerrain(1, 1, make_unique<Mountains>());
            controller.getTerrainMap().setTerrain(2, 1, make_unique<Plains>());
            controller.getTerrainMap().setTerrain(3, 1, make_unique<Mountains>());

            shared_ptr<Unit> soldier = controller.createUnit(assaultFactory, 0, 0, "Soldier");
            shared_ptr<Unit> sniper = controller.createUnit(marksmanFactory, 0, 1, "Sniper");
            shared_ptr<Unit> jetpack = controller.createUnit(jetpackFactory, 2, 1, "JetpackTrooper");

            if (soldier == nullptr || sniper == nullptr || jetpack == nullptr) {
                cout << "Не удалось создать всех юнитов.\n";
                break;
            }

            cout << "\n1. Soldier перемещается по лесу:\n";
            controller.moveUnit(*soldier, 1, 0);

            cout << "\n2. Soldier перемещается по болоту:\n";
            controller.moveUnit(*soldier, 1, 0);

            cout << "\n3. Soldier пытается пройти через горы:\n";
            controller.moveUnit(*soldier, 1, 0);

            cout << "\n4. Sniper пытается пройти через горы:\n";
            controller.moveUnit(*sniper, 1, 0);

            cout << "\n5. JetpackTrooper пытается пройти через горы:\n";
            controller.moveUnit(*jetpack, 1, 0);

            cout << "\nИтоговые координаты:\n";
            cout << "Soldier: (" << soldier->getX() << ", " << soldier->getY() << ")\n";
            cout << "Sniper: (" << sniper->getX() << ", " << sniper->getY() << ")\n";
            cout << "JetpackTrooper: (" << jetpack->getX() << ", " << jetpack->getY() << ")\n";

            cout << "\nВыход - Enter";
            cin.ignore();
            cin.get();
            clear();
            break;
        }
        case 10: {
            clear();
            cout << "Демонстрация взаимодействия с нейтральными объектами (пятый этап)\n";

            GameController controller(1000, 5, 0, 100, 5, 5);

            shared_ptr<Unit> soldier = controller.createUnit(assaultFactory, 0, 0, "Soldier");
            shared_ptr<Unit> sniper = controller.createUnit(marksmanFactory, 1, 0, "Sniper");

            if (soldier == nullptr || sniper == nullptr) {
                cout << "Не удалось создать юнитов.\n";
                break;
            }

            controller.getTerrainMap().setNeutralObjectAt(0, 0, make_shared<SupplyCrate>(controller.getBase(), 50));
            controller.getTerrainMap().setNeutralObjectAt(1, 0, make_shared<Mine>(20));
            controller.getTerrainMap().setNeutralObjectAt(2, 0, make_shared<PowerCrate>(15));
            controller.getTerrainMap().setNeutralObjectAt(0, 1, make_shared<Dispenser>(30));
            controller.getTerrainMap().setNeutralObjectAt(1, 1, make_shared<PowerCrate>(10));

            cout << "\n1. Soldier взаимодействует с SupplyCrate:\n";
            cout << "Ресурсы до взаимодействия: " << controller.getBase().getResources() << "\n";
            controller.interactWithObject(*soldier);
            cout << "Ресурсы после взаимодействия: " << controller.getBase().getResources() << "\n";

            cout << "\n2. Soldier перемещается к Mine:\n";
            soldier->move(1, 0);
            cout << "Здоровье до взаимодействия: " << soldier->getHealth().getCurrentHealth() << "\n";
            controller.interactWithObject(*soldier);
            cout << "Здоровье после взаимодействия: " << soldier->getHealth().getCurrentHealth() << "\n";

            cout << "\n3. Soldier перемещается к PowerCrate:\n";
            soldier->move(1, 0);
            cout << "Атака до взаимодействия: " << soldier->getAttack().getDamage() << "\n";
            controller.interactWithObject(*soldier);
            cout << "Атака после взаимодействия: " << soldier->getAttack().getDamage() << "\n";

            cout << "\n4. Sniper перемещается к Dispenser:\n";
            sniper->move(-1, 1);
            sniper->takeDamage(30);
            cout << "Здоровье до взаимодействия: " << sniper->getHealth().getCurrentHealth() << "\n";
            controller.interactWithObject(*sniper);
            cout << "Здоровье после взаимодействия: " << sniper->getHealth().getCurrentHealth() << "\n";

            cout << "\n5. Sniper перемещается к PowerCrate:\n";
            sniper->move(1, 0);
            cout << "Мана до взаимодействия: " << sniper->getMana() << "\n";
            controller.interactWithObject(*sniper);
            cout << "Мана после взаимодействия: " << sniper->getMana() << "\n";

            cout << "\nВыход - Enter";
            cin.ignore();
            cin.get();
            clear();
            break;
        }
        case 11: {
            clear();
            cout << "Демонстрация уничтожения юнита и уведомления базы (пятый этап)\n";

            GameController controller(1000, 3, 0, 100, 5, 5);

            shared_ptr<Unit> soldier = controller.createUnit(assaultFactory, 0, 0, "Soldier");
            shared_ptr<Unit> sniper = controller.createUnit(marksmanFactory, 1, 0, "Sniper");

            if (soldier == nullptr || sniper == nullptr) {
                cout << "Не удалось создать юнитов.\n";
                break;
            }

            cout << "\nКоличество юнитов до уничтожения: "
                << controller.getBase().getUnitCount() << "\n";

            cout << "\nНаносим Soldier смертельный урон:\n";
            soldier->takeDamage(10000);

            cout << "\nКоличество юнитов после уведомления Observer: "
                << controller.getBase().getUnitCount() << "\n";

            cout << "\nУдаляем уничтоженного Soldier через GameController:\n";
            controller.removeDestroyedUnit(*soldier);

            cout << "\nСоздаём нового Pyro на освободившееся место:\n";
            shared_ptr<Unit> pyro = controller.createUnit(specialistFactory, 2, 0, "Pyro");

            if (pyro != nullptr) {
                cout << "Pyro успешно создан. ID: " << pyro->getId() << "\n";
            }

            cout << "\nИтоговое количество юнитов: "
                << controller.getBase().getUnitCount() << "\n";

            cout << "\nВыход - Enter";
            cin.ignore();
            cin.get();
            clear();
            break;
        }


        }
    }

    return 0;
}