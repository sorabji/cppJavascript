/**
 * warehouse is a collection of inventoryItems...assignment is to sketch out
 * methods for += and -= operators.
 */
class Warehouse{

    /**
     * this method adds the InventoryItem into the Warehouse
     */
    friend Warehouse& operator+=(const InventoryItem &rhs){
    }

    /**
     * this method removes the InventoryItem from the Warehouse
     */
    friend Warehouse& operator-=(const InventoryItem &rhs){
    }
};
