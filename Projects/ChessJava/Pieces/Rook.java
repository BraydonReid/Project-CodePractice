package Pieces;

import Board.Board;

public class Rook extends pieces {
    public Rook(boolean white) {
        super(white);
    }

    public String getImage() {
        if (isWhite()) {
            return "/ChessPiecesImages/WhiteRook.png";
        }
        return "/ChessPiecesImages/BlackRook.png";
    }

    public int getValue() {
        return 5;
    }
    
    public boolean canMove(Board board, Position start, Position end) {
        if (start.getRow() == end.getRow() && start.getCol() == end.getCol()) {
            return false;
        }

        if (start.getRow() != end.getRow() && start.getCol() != end.getCol()) {
            return false;
        }

        if (!isPathClear(board.getBoard(), start, end)) {
            return false;
        }

        char endPiece = board.getBoard()[end.getRow()][end.getCol()];
        if (endPiece != '-') {
            boolean isEndPieceWhite = Character.isUpperCase(endPiece);
            if (this.isWhite() == isEndPieceWhite) {
                return false;
            }
        }

        return true;
    }

    public boolean isPathClear(char[][] board, Position start, Position end) {
        int startX = start.getRow();
        int startY = start.getCol();
        int endX = end.getRow();
        int endY = end.getCol();

        if (startX == endX) {
            int yDirection = 1;
            if (endY < startY) {
                yDirection = -1;
            }

            for (int y = startY + yDirection; y != endY; y += yDirection) {
                if (y < 0 || y >= 8) {
                    return false;
                }
                if (board[startX][y] != '-') {
                    return false;
                }
            }
        } else if (startY == endY) {
            int xDirection = 1;
            if (endX < startX) {
                xDirection = -1;
            }
            for (int x = startX + xDirection; x != endX; x += xDirection) {
                if (x < 0 || x >= 8) {
                    return false;
                }
                if (board[x][startY] != '-') {
                    return false;
                }
            }
        } else {

            return false;
        }
        return true;
    }
}
