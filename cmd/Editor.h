/*
 * file:                  Editor.h
 * description:           Data-structures and processing.
 * author:                Your Name Here <Your Email Address Here>.
 * date:                  The Date Here.
 */

#ifndef EDITOR_H
#define EDITOR_H

// base code includes
#include                  <CommandLineParser.h>

// vtk wrappers
#include                  <vtkContourForests.h>

// VTK includes
#include                  <vtkDataSet.h>

#include                  <vtkXMLUnstructuredGridReader.h>
#include                  <vtkXMLImageDataReader.h>

#include                  <vtkXMLUnstructuredGridWriter.h>

class Editor : public Debug {

public:

    Editor();

    ~Editor();

    int execute();

    vtkDataSet* getData() const {
        return grid_;
    };

    int init(int &argc, char **argv);
    int saveData(const string &fileName) const;

    template<class TReader>
    vtkDataSet *ReadAnXMLFile(const char*fileName){
      vtkSmartPointer<TReader> reader = vtkSmartPointer<TReader>::New();
      reader->SetFileName(fileName);
      // handle debug messages
      {
        stringstream msg;
        msg << "[Editor] Reading input mesh..." << endl;
        dMsg(cout, msg.str(), 1);
      }
      reader->Update();
      reader->GetOutput()->Register(reader);
      return vtkDataSet::SafeDownCast(reader->GetOutput());
    }


protected:
 int                debug_;
 int                core_;
 int                fieldId_;
 int                treeType_;
 vtkContourForests *contourTree_;
 vtkDataSet *       grid_;
 string             inputFilePath_;
 bool               lessPartitions_;
 int                method_;
 double             threshold_;

 int loadData();

};

#endif // EDITOR_H
