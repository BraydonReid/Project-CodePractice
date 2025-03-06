package Board;
import Pieces.Position;



public class SavedMoves extends Board {
    
    private Position start;
    private Position end;
    private char pieceMoved;
    private char pieceKilled;
    private boolean isWhite;
    private boolean isKilled;

    public SavedMoves(Position start, Position end, char pieceMoved, char pieceKilled, boolean isWhite, boolean isKilled) {
        this.start = start;
        this.end = end;
        this.pieceMoved = pieceMoved;
        this.pieceKilled = pieceKilled;
        this.isWhite = isWhite;
        this.isKilled = isKilled;
    }

    public Position getStart() {
        return start;
    }

    public Position getEnd() {
        return end;
    }

    public char getPieceMoved() {
        return pieceMoved;
    }

    public char getPieceKilled() {
        return pieceKilled;
    }

    public boolean isWhite() {
        return isWhite;
    }

    public boolean isKilled() {
        return isKilled;
    }

    public void undoMove(Board board) {
        board.move(end, start);
        if (isKilled) {
            board.getBoard()[end.getRow()][end.getCol()] = pieceKilled;
        }
    }

    public void redoMove(Board board) {
        board.move(start, end);
        if (isKilled) {
            board.getBoard()[end.getRow()][end.getCol()] = pieceKilled;
        }
    }
}
