# Directoris per defecte de les diferents llibreries. Si vols que siguin uns altres, simplement has de declarar
# com a variables de sistema les que vulguis substituir. Ex.: export ITKLIBDIR=/usr/lib64/InsightToolkit

# DCMTK Libraries

DCMTKLIBDIR = $$(DCMTKLIBDIR)
isEmpty(DCMTKLIBDIR){
    unix:DCMTKLIBDIR = /usr/lib/dcmtk
    macx:DCMTKLIBDIR = /usr/local/dcmtk-3.6.1_20120515/lib
    win32:DCMTKLIBDIR = $$(SystemDrive)/dcmtk/3.6.1_20120515/lib
}
DCMTKINCLUDEDIR = $$(DCMTKINCLUDEDIR)
isEmpty(DCMTKINCLUDEDIR){
    unix:DCMTKINCLUDEDIR = /usr/include/dcmtk
    macx:DCMTKINCLUDEDIR = /usr/local/dcmtk-3.6.1_20120515/include/dcmtk
    win32:DCMTKINCLUDEDIR = $$(SystemDrive)/dcmtk/3.6.1_20120515/include/dcmtk
}


# VTK Libraries

VTKLIBDIR = $$(VTKLIBDIR)
isEmpty(VTKLIBDIR){
    unix:VTKLIBDIR = /usr/lib
    macx:VTKLIBDIR = /usr/local/lib/vtk-5.6
    win32:VTKLIBDIR = $$(SystemDrive)/VTK/6.1.0/lib
}
VTKINCLUDEDIR = $$(VTKINCLUDEDIR)
isEmpty(VTKINCLUDEDIR){
    unix:VTKINCLUDEDIR = /usr/include/vtk-5.6
    macx:VTKINCLUDEDIR = /usr/local/include/vtk-5.6
    win32:VTKINCLUDEDIR = $$(SystemDrive)/VTK/6.1.0/include/vtk-6.1
}


# ITK Libraries

ITKLIBDIR = $$(ITKLIBDIR)
isEmpty(ITKLIBDIR){
    unix:ITKLIBDIR = /usr/lib/InsightToolkit
    macx:ITKLIBDIR = /usr/local/lib/InsightToolkit
    win32:ITKLIBDIR = $$(SystemDrive)/InsightToolkit/4.6.1/lib
}
ITKINCLUDEDIR = $$(ITKINCLUDEDIR)
isEmpty(ITKINCLUDEDIR){
    unix:ITKINCLUDEDIR = /usr/include/InsightToolkit
    macx:ITKINCLUDEDIR = /usr/local/include/InsightToolkit
    win32:ITKINCLUDEDIR = $$(SystemDrive)/InsightToolkit/4.6.1/include/ITK-4.6
}

# GDCM Libraries

GDCMLIBDIR = $$(GDCMLIBDIR)
isEmpty(GDCMLIBDIR){
    unix:GDCMLIBDIR = /usr/lib/gdcm
    macx:GDCMLIBDIR = /usr/local/lib/gdcm-2.0
    win32:GDCMLIBDIR = $$(SystemDrive)/gdcm/2.4.4/lib
}
GDCMINCLUDEDIR = $$(GDCMINCLUDEDIR)
isEmpty(GDCMINCLUDEDIR){
    unix:GDCMINCLUDEDIR = /usr/include/gdcm
    macx:GDCMINCLUDEDIR = /usr/local/include/gdcm-2.0
    win32:GDCMINCLUDEDIR = $$(SystemDrive)/gdcm/2.4.4/include/gdcm-2.4
}

# Log4cxx Libraries

LOG4CXXLIBDIR = $$(LOG4CXXLIBDIR)
isEmpty(LOG4CXXLIBDIR){
    unix:LOG4CXXLIBDIR = /usr/lib
    macx:LOG4CXXLIBDIR = /usr/local/lib/log4cxx
    win32:LOG4CXXLIBDIR = C:/log4cxx
}
LOG4CXXINCLUDEDIR = $$(LOG4CXXINCLUDEDIR)
isEmpty(LOG4CXXINCLUDEDIR){
    unix:LOG4CXXINCLUDEDIR = /usr/include/log4cxx
    macx:LOG4CXXINCLUDEDIR = /usr/local/include
    win32:LOG4CXXINCLUDEDIR = C:/log4cxx/include
}

# Threadweaver libraries

THREADWEAVERLIBDIR = $$(THREADWEAVERLIBDIR)
isEmpty(THREADWEAVERLIBDIR){
    unix:THREADWEAVERLIBDIR = /usr/lib
    macx:THREADWEAVERLIBDIR = /usr/local/lib/threadweaver
    win32:THREADWEAVERLIBDIR = $$(SystemDrive)/ThreadWeaver/5.3.0/lib
}
THREADWEAVERINCLUDEDIR = $$(THREADWEAVERINCLUDEDIR)
isEmpty(THREADWEAVERINCLUDEDIR){
    unix:THREADWEAVERINCLUDEDIR = /usr/include
    macx:THREADWEAVERINCLUDEDIR = /usr/local/include
    win32:THREADWEAVERINCLUDEDIR = $$(SystemDrive)/ThreadWeaver/5.3.0/include/KF5
}


# CUDA Libraries

CUDALIBDIR = $$(CUDALIBDIR)
isEmpty(CUDALIBDIR){
    unix:CUDALIBDIR = /usr/local/cuda/lib
}
CUDAINCLUDEDIR = $$(CUDAINCLUDEDIR)
isEmpty(CUDAINCLUDEDIR){
    unix:CUDAINCLUDEDIR = /usr/local/cuda/include
}
# De moment cal el CUDA SDK, però s'hauria de poder treballar sense ell
CUDASDKINCLUDEDIR = $$(CUDASDKINCLUDEDIR)
isEmpty(CUDASDKINCLUDEDIR){
    unix:CUDASDKINCLUDEDIR = /usr/local/cuda-sdk/common/inc
}
