include("D:/QT/gitqt/flights_arrangement/PersonCenter/build/Desktop_Qt_6_9_3_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/PersonCenter-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "D:/QT/gitqt/flights_arrangement/PersonCenter/build/Desktop_Qt_6_9_3_MinGW_64_bit-Debug/PersonCenter.exe"
    GENERATE_QT_CONF
)
