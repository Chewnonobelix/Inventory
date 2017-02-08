TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS += \
    #pattern \
    Model \
    Vue\
    Controlleur \
    application \
    Plugin \

QMAKE_CXXFLAGS += -std=c++11

TRANSLATIONS += produit_en.ts \
    produit_fr.ts \
    produit_es.ts \
    produit_it.ts \
