#ifndef _BK_QUEUE_H_INCLUDED_
#define _BK_QUEUE_H_INCLUDED_


typedef struct bk_queue_s  bk_queue_t;

struct bk_queue_s {
	int data;
    bk_queue_t  *prev;
    bk_queue_t  *next;
};


#define bk_queue_init(q)                                                     \
    (q)->prev = q;                                                            \
    (q)->next = q


#define bk_queue_empty(h)                                                    \
    (h == (h)->prev)


#define bk_queue_insert_head(h, x)                                           \
    (x)->next = (h)->next;                                                    \
    (x)->next->prev = x;                                                      \
    (x)->prev = h;                                                            \
    (h)->next = x


#define bk_queue_insert_after   bk_queue_insert_head


#define bk_queue_insert_tail(h, x)                                           \
    (x)->prev = (h)->prev;                                                    \
    (x)->prev->next = x;                                                      \
    (x)->next = h;                                                            \
    (h)->prev = x


#define bk_queue_head(h)                                                     \
    (h)->next


#define bk_queue_last(h)                                                     \
    (h)->prev


#define bk_queue_sentinel(h)                                                 \
    (h)


#define bk_queue_next(q)                                                     \
    (q)->next


#define bk_queue_prev(q)                                                     \
    (q)->prev


#define bk_queue_data(q)                                         \
    (q)->data
    
#endif /* _BK_QUEUE_H_INCLUDED_ */
