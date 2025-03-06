package Pieces;

import Board.Board;

public class PieceMovement {
    public boolean Move(Position start, Position end, Board board) {
        char[][] chessBoard = board.getBoard();

        if (start.getRow() < 0 || start.getRow() >= 8 || start.getCol() < 0 || start.getCol() >= 8 ||
                end.getRow() < 0 || end.getRow() >= 8 || end.getCol() < 0 || end.getCol() >= 8) {
            return false;
        }

        if (chessBoard[start.getRow()][start.getCol()] == '-') {
            return false;
        }

        // Move piece
        chessBoard[end.getRow()][end.getCol()] = chessBoard[start.getRow()][start.getCol()];
        chessBoard[start.getRow()][start.getCol()] = '-';

        return true;
    }

}
