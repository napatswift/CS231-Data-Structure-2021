/*
 * Napat Dollapavijit
 * 6310400967
 */

void deleteTail(head_t *head){
    node_t *curr = head->first;
    if(head->length==1){
        head->first = curr->next;
        head->last = curr->next;
        head->length -= 1;
        free(curr);
        return ;
    }
    size_t i;
    for(i = 0; i < head->length-2; i++)
        curr = curr->next;
    node_t *target = curr->next;
    curr->next = target->next;
    head->last = curr->next;
    head->length -= 1;
    free(target);
}
