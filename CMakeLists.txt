cmake_minimum_required(VERSION 3.11)
project(PlagiatCity)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra)

# ustawienia SFML-a dla Linuksa/MacOS i Windows - proszę zostawić obie konfiguracje,
# CMake automatycznie użyje właściwej
if (UNIX)
    # konfiguracja dla systemów Unix/Linux/MacOS
    # proszę nie modyfkować pierwszego wpisu, można dopisać kolejne katalogi
    # wpis dla antycznego Ubuntu (dla SFML 2.4)
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULES_PATH})

    # katalog, w którym jest plik SFMLConfig.cmake
    # nowe Ubuntu (SFML 2.5)
    # NIE ZMIENIAĆ, NIE KASOWAĆ !!!
    set ( CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/SFML" ${CMAKE_PREFIX_PATH})

    # dla MacOS lub innej dystrybucji Linuksa - można dopisać DODATKOWY CMAKE_PREFIX_PATH
    # set ( CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/SFML" ${CMAKE_PREFIX_PATH})
endif(UNIX)

if (WIN32)
    # próbujemy linkować statycznie (nie trzeba kopiować plików dll do katalogu projektu)
    set( SFML_STATIC_LIBRARIES TRUE )

    # Jeśli zainstalowaliście w innym miejscu to trzeba tu zmienić katalog na właściwy
    set ( SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML/")
endif(WIN32)


find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

add_executable(PlagiatCity main.cpp Objects/MovableObject.cpp Objects/MovableObject.h Objects/CollidableObject.cpp Objects/CollidableObject.h Bullets/Bullet.cpp Bullets/Bullet.h View/SFMLView.cpp View/SFMLView.h GameBoard.cpp GameBoard.h Tanks/Tank.cpp Tanks/Tank.h Tanks/PlayerTank.cpp Tanks/PlayerTank.h Tanks/AITank.cpp Tanks/AITank.h Tanks/AITanks/LightTank.cpp Tanks/AITanks/LightTank.h Tanks/AITanks/MediumTank.cpp Tanks/AITanks/MediumTank.h Tanks/AITanks/HeavyTank.cpp Tanks/AITanks/HeavyTank.h Bullets/AIBullet.cpp Bullets/AIBullet.h Bullets/PlayerBullet.cpp Bullets/PlayerBullet.h Wall.cpp Wall.h View/SFMLAITankView.cpp View/SFMLAITankView.h View/SFMLPlayerTankView.cpp View/SFMLPlayerTankView.h View/SFMLPlayerTankView.cpp View/TxSp.h View/SFMLBulletView.cpp View/SFMLBulletView.h View/SFMLWallView.cpp View/SFMLWallView.h)
target_link_libraries(PlagiatCity sfml-graphics sfml-audio)
add_executable(PlagiatCityTester Objects/MovableObject.cpp Objects/MovableObject.h test.cpp Objects/CollidableObject.cpp Objects/CollidableObject.h Bullets/Bullet.cpp Bullets/Bullet.h View/SFMLView.cpp View/SFMLView.h GameBoard.cpp GameBoard.h Tanks/Tank.cpp Tanks/Tank.h Tanks/PlayerTank.cpp Tanks/PlayerTank.h Tanks/AITank.cpp Tanks/AITank.h Tanks/AITanks/LightTank.cpp Tanks/AITanks/LightTank.h Tanks/AITanks/MediumTank.cpp Tanks/AITanks/MediumTank.h Tanks/AITanks/HeavyTank.cpp Tanks/AITanks/HeavyTank.h Bullets/AIBullet.cpp Bullets/AIBullet.h Bullets/PlayerBullet.cpp Bullets/PlayerBullet.h Wall.cpp Wall.h View/SFMLAITankView.cpp View/SFMLAITankView.h View/SFMLPlayerTankView.cpp View/SFMLPlayerTankView.h View/SFMLPlayerTankView.cpp View/TxSp.h View/SFMLBulletView.cpp View/SFMLBulletView.h View/SFMLWallView.cpp View/SFMLWallView.h)
target_link_libraries(PlagiatCityTester sfml-graphics sfml-audio)
