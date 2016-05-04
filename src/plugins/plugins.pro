include(../../qtcreator.pri)

TEMPLATE  = subdirs

SUBDIRS   = \
    autotest \
    clangstaticanalyzer \
    coreplugin \
    qmlprofilerextension \
    texteditor \
    cppeditor \
    bineditor \
    diffeditor \
    imageviewer \
    bookmarks \
    projectexplorer \
    vcsbase \
    git \
    cpptools \
    qtsupport \
    qmakeprojectmanager \
    debugger \
    help \
    cmakeprojectmanager \
    resourceeditor \
    genericprojectmanager \
    qmljseditor \
    classview \
    tasklist \
    qmljstools \
    macros \
    android \
    valgrind \
    todo \
    modeleditor \
    qmlprofiler \
    welcome

DO_NOT_BUILD_QMLDESIGNER = $$(DO_NOT_BUILD_QMLDESIGNER)
isEmpty(DO_NOT_BUILD_QMLDESIGNER) {
    SUBDIRS += qmldesigner
} else {
    warning("QmlDesigner plugin has been disabled.")
}


isEmpty(QBS_INSTALL_DIR): QBS_INSTALL_DIR = $$(QBS_INSTALL_DIR)
exists(../shared/qbs/qbs.pro)|!isEmpty(QBS_INSTALL_DIR): \
    SUBDIRS += \
        qbsprojectmanager

# prefer qmake variable set on command line over env var
isEmpty(LLVM_INSTALL_DIR):LLVM_INSTALL_DIR=$$(LLVM_INSTALL_DIR)
exists($$LLVM_INSTALL_DIR) {
    SUBDIRS += clangcodemodel
}

isEmpty(IDE_PACKAGE_MODE) {
    SUBDIRS += \
        helloworld
}

for(p, SUBDIRS) {
    QTC_PLUGIN_DEPENDS =
    include($$p/$${p}_dependencies.pri)
    pv = $${p}.depends
    $$pv = $$QTC_PLUGIN_DEPENDS
}

linux-* {
     SUBDIRS += debugger/ptracepreload.pro
}
