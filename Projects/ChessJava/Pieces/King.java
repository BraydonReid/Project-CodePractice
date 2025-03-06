package Pieces;

import Board.Board;

// Castling is a special move involving the King and the Rook where the King moves two squares towards a
// Rook on its original square and the Rook moves to the square over which the King crossed.

public class King extends pieces {
    private boolean castling = false;
    int x = -1;
    int y = -1;

    public King(boolean white) {
        super(white);
    }

    public King(boolean white, int x ,int y){
        super(white);
        this.x = x;
        this.y = y;
    }

    public String getImage() {
        if (isWhite()) {
            return "/ChessPiecesImages/WhiteKing.png";
        }
        return "/ChessPiecesImages/BlackKing.png";
    }

    public boolean isCastlingDone() {
        return this.castling;
    }

    public void setCastling(boolean castling) {
        this.castling = castling;
    }

    public boolean canMove(Board board, Position start, Position end) {
        char[][] boardArray = board.getBoard();
        int startX = start.getRow();
        int startY = start.getCol();
        int endX = end.getRow();
        int endY = end.getCol();

        char startPiece = boardArray[startX][startY];
        char endPiece = boardArray[endX][endY];


        if (isWhite() && boardArray[endX][endY] >= 65 && boardArray[endX][endY] <= 90) {
            return false;
        }
        if (!isWhite() && boardArray[endX][endY] >= 97 && boardArray[endX][endY] <= 122) {
            return false;
        }

        if (endPiece != '-' && startPiece == endPiece) {
            return false;
        }

        // Can move 1 square in any direction
        int x = Math.abs(startX - endX);
        int y = Math.abs(startY - endY);

        if ((x == 1 && y == 0) || (x == 0 && y == 1) || (x == 1 && y == 1)) {
            return true;
        }

        return isValidCastling(boardArray, start, end);
    }

    private boolean isValidCastling(char[][] board, Position start, Position end) {
        int startX = start.getRow();
        int startY = start.getCol();
        int endX = end.getRow();
        int endY = end.getCol();

        if (this.isCastlingDone()) {
            return false;
        }

        // King must move two squares horizontally to castle
        if (Math.abs(startY - endY) != 2 || startX != endX) {
            return false;
        }

        int yDirection;
        if ((endY - startY) > 0) {
            yDirection = 1;
        } else {
            yDirection = -1;
        }

        for (int y = startY + yDirection; y != endY; y += yDirection) {
            if (board[startX][y] != '-') {
                return false; // Path is not clear
            }
        }

        return true;
    }

    public boolean CastlingMove(Position start, Position end) {
        return true;
    }

    public int getValue() {
        return 0;
    }

}
