#include <Rcpp.h>
using namespace Rcpp;
//' Split a string into codons
//'
//' @author Boris Steipe, \email{boris.steipe@@utoronto.ca}
//' ORCID: 0000-0002-1134-6758
//' License: (c) Author (2018) + MIT
//' Date: 2018-12-31
//' @param cDNA (char) A single string
//' @return (char) a vector of triplets
//' @examples
//' # Split a string into codons
//' cpp_codonSplitCpp("ATGAAATGA")
//' @export
// [[Rcpp::export]]
std::vector<std::string> cpp_codonSplitCpp( std::string cDNA) {

  std::vector<std::string> codons;
  int l = (cDNA.length() + 2 ) / 3;
  codons.reserve(l);
  for( int i=0; i < l; i++ ) {

    codons.push_back( cDNA.substr( i*3, 3 ) );

  }
  return codons;
}

//' @export
// [[Rcpp::export]]
NumericMatrix initializeMatrix(float initVal, int ROW_SIZE, int COL_SIZE){
  NumericMatrix s(ROW_SIZE, COL_SIZE);
  for(int i = 0; i < ROW_SIZE; i++){
    for(int j = 0; j < COL_SIZE; j++){
      s(i, j) = initVal;
    }
  }
  return s;
}
// s <- initializeMatrix(0, 4, 5)

//' @export
// [[Rcpp::export]]
void getseqSimMat(std::string seq1, std::string seq2, float Match, float MisMatch, NumericMatrix s){
  int ROW_SIZE = seq1.size();
  int COL_SIZE = seq2.size();
  for(int j = 0; j < COL_SIZE; j++){
    for(int i = 0; i < ROW_SIZE; i++){
      seq1[i] == seq2[j] ?  s(i, j) = Match : s(i, j) = MisMatch;
    }
  }
}
// getseqSimMat(seq1, seq2, Match, MisMatch, s)

// Match=10; MisMatch=-2; go=22; ge=7; gap=go
// seq1 = "GCAT"; seq2 = "CAGTG"

//' @export
// [[Rcpp::export]]
double meanC(NumericVector x, NumericMatrix s) {
  int n = x.size();
  double total = 0;
  for(int i = 0; i < n; ++i) {
    total += x[i];
  }
  return total / n;
}

//' @export
// [[Rcpp::export]]
NumericMatrix TestMatrixParsing(){
  NumericMatrix xx(4, 5);
  int xsize = xx.nrow() * xx.ncol();
  for (int i = 0; i < xsize; i++) {
    xx[i] = i+100;
  }
  return xx;
}

