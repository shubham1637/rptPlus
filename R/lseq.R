# lseq.R

#' \code{lseq} output a sequence of logarithmically spaced numbers.
#'
#' \code{lseq} works like \code{seq} in that it returns a vector of numbers with
#' \code{from} as the first element, \code{to} as the last element, and
#' \code{length.out} as the length of the vector, but the values are
#' logarithmically spaced.
#'
#' @param from (numeric)       first number in the sequence.
#' @param to (numeric)         last number in the sequence.
#' @param length.out (integer) length of the sequence, a positive integer > 1.
#'                             Default is 10.
#' @return A numeric vector.
#' @author \href{https://orcid.org/0000-0002-1134-6758}{Boris Steipe} (aut)
#' @seealso \code{\link{seq}}
#' @examples
#' # 20 log-spaced values between 0.1 and 10
#' lseq(0.1, 10, length.out = 20)
#'
#' # plot a square, log-spaced grid with 10 cells
#' lim <- c(0.1, 10)
#' N <- 10
#' x <- lseq(lim[1], lim[2], length.out = N + 1)
#' plot(1, 1, xlim=lim, ylim=lim, type="n", axes=FALSE, xlab="", ylab="", asp=1)
#' segments(lim[1], x, lim[2], x, col="#3366FF66")
#' segments(x, lim[1], x, lim[2], col="#3366FF66")
#' @export
lseq <- function(from, to, length.out = 10) {
  x <- seq(log(from), log(to), length.out = length.out)
  return(exp(x))
}

# [END]
