/// \ingroup baseCode
/// \class wtfit::AbstractTriangulation
/// \author Julien Tierny <julien.tierny@lip6.fr>
/// \date January 2016.
/// 
/// \brief AbstractTriangulation is a virtual class that defines an interface 
/// for efficient traversal methods on triangulations of piecewise linear 
/// manifolds. 
///
/// \sa Triangulation

#ifndef _ABSTRACTTRIANGULATION_H
#define _ABSTRACTTRIANGULATION_H

// base code includes
#include                  <Wrapper.h>

using namespace wtfit;

namespace wtfit{
  
  class AbstractTriangulation : public Wrapper{

    
    public:
        
      AbstractTriangulation();
      
      ~AbstractTriangulation();

      virtual int getCellEdge(const int &cellId, 
        const int &localEdgeId, int &edgeId) const = 0;
        
      virtual int getCellEdgeNumber(const int &cellId) const = 0;
      
      virtual const vector<vector<int> > *getCellEdges() = 0;
      
      virtual int getCellNeighbor(const int &cellId,
        const int &localNeighborId, int &neighborId) const = 0;
        
      virtual int getCellNeighborNumber(const int &cellId) const = 0;
      
      virtual const vector<vector<int> > *getCellNeighbors() = 0;
      
      virtual int getCellTriangle(const int &cellId, 
        const int &localTriangleId, int &triangleId) const = 0;
        
      virtual int getCellTriangleNumber(const int &cellId) const = 0;
        
      virtual const vector<vector<int> > *getCellTriangles() = 0;
      
      virtual int getCellVertex(const int &cellId,
        const int &localVertexId, int &vertexId) const = 0;
    
      virtual int getCellVertexNumber(const int &cellId) const = 0;
        
      virtual const vector<pair<int, int> > *getEdges() = 0;
        
      virtual int getEdgeLink(const int &edgeId, 
        const int &localLinkId, vector<long long int> &link) const = 0;
        
      virtual int getEdgeLinkNumber(const int &edgeId) const = 0;
      
      virtual const vector<vector<long long int> > *getEdgeLinks() = 0;
      
      virtual int getEdgeStar(const int &edgeId, 
        const int &localStarId, int &starId) const = 0;
        
      virtual int getEdgeStarNumber(const int &edgeId) const = 0;
      
      virtual const vector<vector<int> > *getEdgeStars() = 0;
     
      virtual int getEdgeTriangle(const int &edgeId, 
        const int &localTriangleId, int &triangleId) const = 0;
        
      virtual int getEdgeTriangleNumber(const int &edgeId) const = 0;
        
      virtual const vector<vector<int> > *getEdgeTriangles() = 0;
      
      virtual int getEdgeVertex(const int &edgeId, 
        const int &localVertexId, int &vertexId) const = 0;
      
      virtual int getNumberOfCells() const = 0;
      
      virtual int getNumberOfEdges() const = 0;
      
      virtual int getNumberOfTriangles() const = 0;
      
      virtual int getNumberOfVertices() const = 0;
      
      virtual const vector<vector<int> > *getTriangles() = 0;
      
      virtual int getTriangleEdge(const int &triangleId,
        const int &localEdgeId, int &edgeId) const = 0;
      
      virtual int getTriangleEdgeNumber(const int &triangleId) const = 0;
      
      virtual const vector<vector<int> > *getTriangleEdges() = 0;
      
      virtual int getTriangleLink(const int &triangleId, 
        const int &localLinkId, vector<long long int> &link) const = 0;
        
      virtual int getTriangleLinkNumber(const int &triangleId) const = 0;
      
      virtual const vector<vector<long long int> > *getTriangleLinks() = 0;
      
      virtual int getTriangleStar(const int &triangleId,
        const int &localStarId, int &starId) const = 0;  
        
      virtual int getTriangleStarNumber(const int &triangleId) const = 0;
      
      virtual const vector<vector<int> > *getTriangleStars() = 0;
      
      virtual int getTriangleVertex(const int &triangleId,
        const int &localVertexId, int &vertexId) const = 0;
      
      virtual int getVertexEdge(const int &vertexId, 
        const int &localEdgeId, int &edgeId) const = 0;
        
      virtual int getVertexEdgeNumber(const int &vertexId) const = 0;
      
      virtual const vector<vector<int> > *getVertexEdges() = 0;
      
      virtual int getVertexLink(const int &vertexId, 
        const int &localLinkId, vector<long long int> &link) const = 0;
        
      virtual int getVertexLinkNumber(const int &vertexId) const = 0;
      
      virtual const vector<vector<long long int> > *getVertexLinks() = 0;
      
      virtual int getVertexNeighbor(const int &vertexId, 
        const int &localNeighborId, int &neighborId) const = 0;
        
      virtual int getVertexNeighborNumber(const int &vertexId) const = 0;
      
      virtual const vector<vector<int> > *getVertexNeighbors() = 0;
      
      virtual int getVertexPoint(const int &vertexId,
        float &x, float &y, float &z) const = 0;
        
      virtual int getVertexStar(const int &vertexId, const int &localStarId,
        int &starId) const = 0;
        
      virtual int getVertexStarNumber(const int &vertexId) const = 0;
        
      virtual const vector<vector<int> > *getVertexStars() = 0;
      
      virtual int getVertexTriangle(const int &vertexId, 
        const int &localTriangleId, int &triangleId) const = 0;
        
      virtual int getVertexTriangleNumber(const int &vertexId) const = 0;
        
      virtual const vector<vector<int> > *getVertexTriangles() = 0;
        
      virtual inline bool hasPreprocessedCellEdges() const{
        return hasPreprocessedCellEdges_;
      }
      
      virtual inline bool hasPreprocessedCellNeighbors() const{
        return hasPreprocessedCellNeighbors_;
      }
      
      virtual inline bool hasPreprocessedCellTriangles() const{
        return hasPreprocessedCellTriangles_;
      }
       
      virtual inline bool hasPreprocessedEdgeLinks() const{
        return hasPreprocessedEdgeLinks_;
      }
       
      virtual inline bool hasPreprocessedEdgeStars() const{
        return hasPreprocessedEdgeStars_;
      }
      
      virtual inline bool hasPreprocessedEdgeTriangles() const{
        return hasPreprocessedEdgeTriangles_;
      }
        
      virtual inline bool hasPreprocessedEdges() const{
        return hasPreprocessedEdges_;
      }
      
      virtual inline bool hasPreprocessedTriangles() const{
        return hasPreprocessedTriangles_;
      }
      
      virtual inline bool hasPreprocessedTriangleEdges() const{
        return hasPreprocessedTriangleEdges_;
      }
      
      virtual inline bool hasPreprocessedTriangleLinks() const{
        return hasPreprocessedTriangleLinks_;
      }
      
      virtual inline bool hasPreprocessedTriangleStars() const{
        return hasPreprocessedTriangleStars_;
      }
        
      virtual inline bool hasPreprocessedVertexEdges() const{
        return hasPreprocessedVertexEdges_;
      }
      
      virtual inline bool hasPreprocessedVertexLinks() const{
        return hasPreprocessedVertexLinks_;
      }
      
      virtual inline bool hasPreprocessedVertexNeighbors() const{
        return hasPreprocessedVertexNeighbors_;
      }
      
      virtual inline bool hasPreprocessedVertexStars() const{
        return hasPreprocessedVertexStars_;
      }
      
      virtual inline bool hasPreprocessedVertexTriangles() const{
        return hasPreprocessedVertexTriangles_;
      }
        
      virtual bool isEmpty() const = 0;

      virtual int preprocessCellEdges(){
        hasPreprocessedCellEdges_ = true;
        return 0;
      }
      
      virtual int preprocessCellNeighbors(){
        hasPreprocessedCellNeighbors_ = true;
        return 0;
      }
      
      virtual int preprocessCellTriangles(){
        hasPreprocessedCellTriangles_ = true;
        return 0;
      }
      
      virtual int preprocessEdges(){
        hasPreprocessedEdges_ = true;
        return 0;
      }
      
      virtual int preprocessEdgeLinks(){
        hasPreprocessedEdgeLinks_ = true;
        return 0;
      }
      
      virtual int preprocessEdgeStars(){
        hasPreprocessedEdgeStars_ = true;
        return 0;
      }
      
      virtual int preprocessEdgeTriangles(){
        hasPreprocessedEdgeTriangles_ = true;
        return 0;
      }
      
      virtual int preprocessTriangles(){
        hasPreprocessedTriangles_ = true;
        return 0;
      }
      
      virtual int preprocessTriangleEdges(){
        hasPreprocessedTriangleEdges_ = true;
        return 0;
      }
      
      virtual int preprocessTriangleLinks(){
        hasPreprocessedTriangleLinks_ = true;
        return 0;
      }
      
      virtual int preprocessTriangleStars(){
        hasPreprocessedTriangleStars_ = true;
        return 0;
      }
      
      virtual int preprocessVertexEdges() { 
        hasPreprocessedVertexEdges_ = true;
        return 0;
      }
      
      virtual int preprocessVertexLinks(){
        hasPreprocessedVertexLinks_ = true;
        return 0;
      }
      
      virtual int preprocessVertexNeighbors(){
        hasPreprocessedVertexNeighbors_ = true;
        return 0;
      }
      
      virtual int preprocessVertexStars(){
        hasPreprocessedVertexStars_ = true;
        return 0;
      }
      
      virtual int preprocessVertexTriangles(){
        hasPreprocessedVertexTriangles_ = true;
        return 0;
      }

    protected:
    
      // empty wrapping to VTK for now
      bool needsToAbort(){ return false;};
      
      int updateProgress(const float &progress) {return 0;};
      
      bool                hasPreprocessedCellEdges_,
                          hasPreprocessedCellNeighbors_,
                          hasPreprocessedCellTriangles_,
                          hasPreprocessedEdges_,
                          hasPreprocessedEdgeLinks_,
                          hasPreprocessedEdgeStars_,
                          hasPreprocessedEdgeTriangles_,
                          hasPreprocessedTriangles_,
                          hasPreprocessedTriangleEdges_,
                          hasPreprocessedTriangleLinks_,
                          hasPreprocessedTriangleStars_,
                          hasPreprocessedVertexEdges_,
                          hasPreprocessedVertexLinks_,
                          hasPreprocessedVertexNeighbors_,
                          hasPreprocessedVertexStars_,
                          hasPreprocessedVertexTriangles_;
      
      vector<vector<int> > 
                          cellEdgeList_;
      vector<vector<int> >
                          cellNeighborList_;
      vector<vector<int> > 
                          cellTriangleList_;
      vector<vector<long long int> >
                          edgeLinkList_;
      vector<pair<int, int> >
                          edgeList_;
      vector<vector<int> >
                          edgeStarList_;
      vector<vector<int> >
                          edgeTriangleList_;
      vector<vector<int> >
                          triangleList_;
      vector<vector<int> > 
                          triangleEdgeList_;
      vector<vector<long long int> >
                          triangleLinkList_;
      vector<vector<int> >
                          triangleStarList_;
      vector<vector<int> > 
                          vertexEdgeList_;
      vector<vector<long long int> >
                          vertexLinkList_;
      vector<vector<int> > 
                          vertexNeighborList_;
      vector<vector<int> >
                          vertexStarList_;
      vector<vector<int> >
                          vertexTriangleList_;
  };
}

// if the package is not a template, comment the following line
// #include                  <AbstractTriangulation.cpp>

#endif // _ABSTRACTTRIANGULATION_H
