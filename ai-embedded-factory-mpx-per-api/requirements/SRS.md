# Software Requirements Specification (SRS) — MPX RTOS Clone (Per-API)

## 1. Scope
This SRS defines a **1:1 behavioral clone** of MPX RTOS v1.0.0.

Normative sources:
- **MPX-RTOS-pthreads-card.rtf (updated)** — normative API surface (signatures)
- **MPX-User-Manual-V1-0-0.docx** — normative semantics for APIs defined in Chapter 7

## 2. Conformance Rules
- If an API is defined in the User Manual, the User Manual semantics are normative.
- All APIs listed in the updated Reference Card SHALL be implemented.
- If an API is only listed in the Reference Card, behavior SHALL match MPX RTOS; additional evidence may be required during V&V.

## 3. System-Level Requirements
### REQ-SYS-0001 — System start (`mpx_pthread_start`)
The implementation SHALL provide `mpx_pthread_start()` and SHALL follow the User Manual start-flow semantics.

### REQ-SYS-0002 — Complete API surface
The implementation SHALL expose the complete API surface listed in the updated Reference Card.

### REQ-SYS-0003 — Traceability
All requirements SHALL be traced to code and verification artifacts in `requirements/TRACE_MATRIX.csv` (delimiter `;`).

## 4. Per-API Requirements (Reference Card Surface)
Each API below is a normative requirement. Where the User Manual defines the API, the semantics described there are normative.

### REQ-API-0001 — API `_mq_extend_open`
**Prototype (Reference Card)**
```c
mqd_t mpx _mq_extend_open(const char * queue_name, int operation, mode_t mode, struct mq_attr * queue_attributes, mq_extendattr_t * extend_attributes);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0002 — API `_pthread_attr_getcontrolsize`
**Prototype (Reference Card)**
```c
int mpx _pthread_attr_getcontrolsize(pthread_attr_t * thread_attributes, size_t * thread_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0003 — API `_pthread_attr_getname`
**Prototype (Reference Card)**
```c
int mpx _pthread_attr_getname(pthread_attr_t * thread_attributes, char ** name);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0004 — API `_pthread_attr_getpriority`
**Prototype (Reference Card)**
```c
int mpx _pthread_attr_getpriority(pthread_attr_t * thread_attributes, int * priority);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0005 — API `_pthread_attr_gettimeslice`
**Prototype (Reference Card)**
```c
int mpx _pthread_attr_gettimeslice(pthread_attr_t * thread_attributes, u_long * thread_time_slice);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0006 — API `_pthread_attr_setcontroladdr`
**Prototype (Reference Card)**
```c
int mpx _pthread_attr_setcontroladdr(pthread_attr_t * thread_attributes, void * thread_control_address, size_t thread_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0007 — API `_pthread_attr_setname`
**Prototype (Reference Card)**
```c
int mpx _pthread_attr_setname(pthread_attr_t * thread_attributes, char * name);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0008 — API `_pthread_attr_setpriority`
**Prototype (Reference Card)**
```c
int mpx _pthread_attr_setpriority(pthread_attr_t * thread_attributes, int priority);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0009 — API `_pthread_attr_settimeslice`
**Prototype (Reference Card)**
```c
int mpx _pthread_attr_settimeslice(pthread_attr_t * thread_attributes, u_long thread_time_slice);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0010 — API `_pthread_condattr_getcontroladdr`
**Prototype (Reference Card)**
```c
int mpx _pthread_condattr_getcontroladdr(pthread_condattr_t * condition_var_attributes, void ** condition_var_control_address);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0011 — API `_pthread_condattr_getname`
**Prototype (Reference Card)**
```c
int mpx _pthread_condattr_getname(pthread_condattr_t * condition_var_attributes, char ** name);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0012 — API `_pthread_condattr_setcontroladdr`
**Prototype (Reference Card)**
```c
int mpx _pthread_condattr_setcontroladdr(pthread_condattr_t * condition_var_attributes, void * condition_var_control_address, size_t condition_var_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0013 — API `_pthread_condattr_setname`
**Prototype (Reference Card)**
```c
int mpx _pthread_condattr_setname(pthread_condattr_t * condition_var_attributes, char * name);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0014 — API `_pthread_event_flags_create`
**Prototype (Reference Card)**
```c
int mpx _pthread_event_flags_create(pthread_event_flags_t * event_flags_handle, pthread_event_flagsattr_t * event_flags_attributes);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0015 — API `_pthread_event_flags_destroy`
**Prototype (Reference Card)**
```c
int mpx _pthread_event_flags_destroy(pthread_event_flags_t * event_flags_handle);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0016 — API `_pthread_event_flags_set`
**Prototype (Reference Card)**
```c
int mpx _pthread_event_flags_set(pthread_event_flags_t * event_flags_handle, u_long events_to_set);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0017 — API `_pthread_event_flags_timedwait`
**Prototype (Reference Card)**
```c
int mpx _pthread_event_flags_timedwait(pthread_event_flags_t * event_flags_handle, u_long requested_events, int all_or_any, u_long * received_events, tick_t timeout_ticks);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0018 — API `_pthread_event_flags_trywait`
**Prototype (Reference Card)**
```c
int mpx _pthread_event_flags_trywait(pthread_event_flags_t * event_flags_handle, u_long requested_events, int all_or_any, u_long * received_events);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0019 — API `_pthread_event_flags_wait`
**Prototype (Reference Card)**
```c
int mpx _pthread_event_flags_wait(pthread_event_flags_t * event_flags_handle, u_long requested_events, int all_or_any, u_long * received_events);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0020 — API `_pthread_event_flagsattr_destroy`
**Prototype (Reference Card)**
```c
int mpx _pthread_event_flagsattr_destroy(pthread_event_flagsattr_t * event_flags_attributes);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0021 — API `_pthread_event_flagsattr_getcontrolsize`
**Prototype (Reference Card)**
```c
int mpx _pthread_event_flagsattr_getcontrolsize(pthread_event_flagsattr_t * event_flags_attributes, size_t * event_flags_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0022 — API `_pthread_event_flagsattr_getname`
**Prototype (Reference Card)**
```c
int mpx _pthread_event_flagsattr_getname(pthread_event_flagsattr_t * event_flags_attributes, char ** name);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0023 — API `_pthread_event_flagsattr_init`
**Prototype (Reference Card)**
```c
int mpx _pthread_event_flagsattr_init(pthread_event_flagsattr_t * event_flags_attributes);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0024 — API `_pthread_event_flagsattr_setcontroladdr`
**Prototype (Reference Card)**
```c
int mpx _pthread_event_flagsattr_setcontroladdr(pthread_event_flagsattr_t * event_flags_attributes, void * event_flags_control_address, size_t event_flags_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0025 — API `_pthread_event_flagsattr_setname`
**Prototype (Reference Card)**
```c
int mpx _pthread_event_flagsattr_setname(pthread_event_flagsattr_t * event_flags_attributes, char * name);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0026 — API `_pthread_fastqueue_destroy`
**Prototype (Reference Card)**
```c
int mpx _pthread_fastqueue_destroy(pthread_fastqueue_t * fastqueue_handle);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0027 — API `_pthread_fastqueue_receive`
**Prototype (Reference Card)**
```c
int mpx _pthread_fastqueue_receive(pthread_fastqueue_t * fastqueue_handle, u_long * message_destination, size_t message_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0028 — API `_pthread_fastqueue_send`
**Prototype (Reference Card)**
```c
int mpx _pthread_fastqueue_send(pthread_fastqueue_t * fastqueue_handle, u_long * message_source, size_t message_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0029 — API `_pthread_fastqueue_timedsend`
**Prototype (Reference Card)**
```c
int mpx _pthread_fastqueue_timedsend(pthread_fastqueue_t * fastqueue_handle, u_long * message_source, size_t message_size, tick_t timeout_ticks);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0030 — API `_pthread_fastqueue_tryreceive`
**Prototype (Reference Card)**
```c
int mpx _pthread_fastqueue_tryreceive(pthread_fastqueue_t * fastqueue_handle, u_long * message_destination, size_t message_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0031 — API `_pthread_fastqueue_trysend`
**Prototype (Reference Card)**
```c
int mpx _pthread_fastqueue_trysend(pthread_fastqueue_t * fastqueue_handle, u_long * message_source, size_t message_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0032 — API `_pthread_fastqueueattr_destroy`
**Prototype (Reference Card)**
```c
int mpx _pthread_fastqueueattr_destroy(pthread_fastqueueattr_t * fastqueue_attributes);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0033 — API `_pthread_fastqueueattr_getcontroladdr`
**Prototype (Reference Card)**
```c
int mpx _pthread_fastqueueattr_getcontroladdr(pthread_fastqueueattr_t * fastqueue_attributes, void ** fastqueue_control_address);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0034 — API `_pthread_fastqueueattr_getcontrolsize`
**Prototype (Reference Card)**
```c
int mpx _pthread_fastqueueattr_getcontrolsize(pthread_fastqueueattr_t * fastqueue_attributes, size_t * fastqueue_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0035 — API `_pthread_fastqueueattr_getqueueaddr`
**Prototype (Reference Card)**
```c
int mpx _pthread_fastqueueattr_getqueueaddr(pthread_fastqueueattr_t* fastqueue_attributes, void ** fastqueue_memory_address);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0036 — API `_pthread_fastqueueattr_getqueuesize`
**Prototype (Reference Card)**
```c
int mpx _pthread_fastqueueattr_getqueuesize(pthread_fastqueueattr_t* fastqueue_attributes, size_t * fastqueue_memory_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0037 — API `_pthread_fastqueueattr_init`
**Prototype (Reference Card)**
```c
int mpx _pthread_fastqueueattr_init(pthread_fastqueueattr_t * fastqueue_attributes);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0038 — API `_pthread_fastqueueattr_setcontroladdr`
**Prototype (Reference Card)**
```c
int mpx _pthread_fastqueueattr_setcontroladdr(pthread_fastqueueattr_t * fastqueue_attributes, void * fastqueue_control_address, size_t fastqueue_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0039 — API `_pthread_fastqueueattr_setname`
**Prototype (Reference Card)**
```c
int mpx _pthread_fastqueueattr_setname(pthread_fastqueueattr_t * fastqueue_attributes, char * fastqueue_name);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0040 — API `_pthread_fastqueueattr_setqueueaddr`
**Prototype (Reference Card)**
```c
int mpx _pthread_fastqueueattr_setqueueaddr(pthread_fastqueueattr_t* fastqueue_attributes, void * fastqueue_memory_address, size_t fastqueue_memory_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0041 — API `_pthread_information_get`
**Prototype (Reference Card)**
```c
int mpx _pthread_information_get(pthread_t thread_handle, char ** name, int * state, int * priority, void ** stack_limit, void ** stack_pointer, u_long * minimum_stack, pthread_t * next_thread);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0042 — API `_pthread_memory_manager_get`
**Prototype (Reference Card)**
```c
int mpx _pthread_memory_manager_get(void * (** memory_allocate_pointer)(u_int type, u_long size), void (** memory_release_pointer)(u_int type, void *memory_to_release));
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0043 — API `_pthread_memory_manager_set`
**Prototype (Reference Card)**
```c
int mpx _pthread_memory_manager_set(void * (* memory_allocate_pointer)(u_int type, u_long size), void (* memory_release_pointer)(u_int type, void *memory_to_release));
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0044 — API `_pthread_memorypool_allocate`
**Prototype (Reference Card)**
```c
int mpx _pthread_memorypool_allocate(pthread_memorypool_t * memorypool_handle, void ** allocated_memory, size_t request_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0045 — API `_pthread_memorypool_create`
**Prototype (Reference Card)**
```c
int mpx _pthread_memorypool_create(pthread_memorypool_t * memorypool_handle, pthread_memorypoolattr_t * memorypool_attributes, void * pool_start, size_t pool_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0046 — API `_pthread_memorypool_destroy`
**Prototype (Reference Card)**
```c
int mpx _pthread_memorypool_destroy(pthread_memorypool_t * memorypool_handle);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0047 — API `_pthread_memorypool_timedallocate`
**Prototype (Reference Card)**
```c
int mpx _pthread_memorypool_timedallocate(pthread_memorypool_t * memorypool_handle, void ** allocated_memory, size_t request_size, tick_t timeout_ticks);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0048 — API `_pthread_memorypool_tryallocate`
**Prototype (Reference Card)**
```c
int mpx _pthread_memorypool_tryallocate(pthread_memorypool_t * memorypool_handle, void ** allocated_memory, size_t request_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0049 — API `_pthread_memorypoolattr_destroy`
**Prototype (Reference Card)**
```c
int mpx _pthread_memorypoolattr_destroy(pthread_memorypoolattr_t * memorypool_attributes);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0050 — API `_pthread_memorypoolattr_getcontroladdr`
**Prototype (Reference Card)**
```c
int mpx _pthread_memorypoolattr_getcontroladdr(pthread_memorypoolattr_t * memorypool_attributes, void ** memorypool_control_address);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0051 — API `_pthread_memorypoolattr_getname`
**Prototype (Reference Card)**
```c
int mpx _pthread_memorypoolattr_getname(pthread_memorypoolattr_t * memorypool_attributes, char ** name);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0052 — API `_pthread_memorypoolattr_init`
**Prototype (Reference Card)**
```c
int mpx _pthread_memorypoolattr_init(pthread_memorypoolattr_t * memorypool_attributes);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0053 — API `_pthread_memorypoolattr_setcontroladdr`
**Prototype (Reference Card)**
```c
int mpx _pthread_memorypoolattr_setcontroladdr(pthread_memorypoolattr_t * memorypool_attributes, void * memorypool_control_address, size_t memorypool_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0054 — API `_pthread_mutexattr_getcontroladdr`
**Prototype (Reference Card)**
```c
int mpx _pthread_mutexattr_getcontroladdr(pthread_mutexattr_t * mutex_attributes, void ** mutex_control_address);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0055 — API `_pthread_mutexattr_getname`
**Prototype (Reference Card)**
```c
int mpx _pthread_mutexattr_getname(pthread_mutexattr_t * mutex_attributes, char ** name);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0056 — API `_pthread_mutexattr_setcontroladdr`
**Prototype (Reference Card)**
```c
int mpx _pthread_mutexattr_setcontroladdr(pthread_mutexattr_t * mutex_attributes, void * mutex_control_address, size_t mutex_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0057 — API `_pthread_mutexattr_setname`
**Prototype (Reference Card)**
```c
int mpx _pthread_mutexattr_setname(pthread_mutexattr_t * mutex_attributes, char * name);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0058 — API `_pthread_partitionpool_create`
**Prototype (Reference Card)**
```c
int mpx _pthread_partitionpool_create(pthread_partitionpool_t * partitionpool_handle, pthread_partitionpoolattr_t * partitionpool_attributes, void * pool_start, size_t pool_size, size_t partition_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0059 — API `_pthread_partitionpool_destroy`
**Prototype (Reference Card)**
```c
int mpx _pthread_partitionpool_destroy(pthread_partitionpool_t * partitionpool_handle);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0060 — API `_pthread_partitionpool_timedallocate`
**Prototype (Reference Card)**
```c
int mpx _pthread_partitionpool_timedallocate(pthread_partitionpool_t * partitionpool_handle, void ** allocated_memory, size_t request_size, tick_t timeout_ticks);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0061 — API `_pthread_partitionpool_tryallocate`
**Prototype (Reference Card)**
```c
int mpx _pthread_partitionpool_tryallocate(pthread_partitionpool_t * partitionpool_handle, void ** allocated_memory, size_t request_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0062 — API `_pthread_partitionpoolattr_destroy`
**Prototype (Reference Card)**
```c
int mpx _pthread_partitionpoolattr_destroy(pthread_partitionpoolattr_t * partitionpool_attributes);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0063 — API `_pthread_partitionpoolattr_getcontroladdr`
**Prototype (Reference Card)**
```c
int mpx _pthread_partitionpoolattr_getcontroladdr(pthread_partitionpoolattr_t * partitionpool_attributes, void ** partitionpool_control_address);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0064 — API `_pthread_partitionpoolattr_getcontrolsize`
**Prototype (Reference Card)**
```c
int mpx _pthread_partitionpoolattr_getcontrolsize(pthread_partitionpoolattr_t * partitionpool_attributes, size_t * partitionpool_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0065 — API `_pthread_partitionpoolattr_getname`
**Prototype (Reference Card)**
```c
int mpx _pthread_partitionpoolattr_getname(pthread_partitionpoolattr_t * partitionpool_attributes, char ** name);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0066 — API `_pthread_partitionpoolattr_init`
**Prototype (Reference Card)**
```c
int mpx _pthread_partitionpoolattr_init(pthread_partitionpoolattr_t * partitionpool_attributes);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0067 — API `_pthread_partitionpoolattr_setcontroladdr`
**Prototype (Reference Card)**
```c
int mpx _pthread_partitionpoolattr_setcontroladdr(pthread_partitionpoolattr_t * partitionpool_attributes, void * partitionpool_control_address, size_t partitionpool_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0068 — API `_pthread_partitionpoolattr_setname`
**Prototype (Reference Card)**
```c
int mpx _pthread_partitionpoolattr_setname(pthread_partitionpoolattr_t * partitionpool_attributes, char * name);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0069 — API `_pthread_priority_change`
**Prototype (Reference Card)**
```c
int mpx _pthread_priority_change(pthread_t thread_handle, int new_priority, int * old_priority);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0070 — API `_pthread_stack_check`
**Prototype (Reference Card)**
```c
int mpx _pthread_stack_check(pthread_t thread_handle, u_long * minimum_available_stack);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0071 — API `_pthread_start`
**Prototype (Reference Card)**
```c
int mpx _pthread_start(u_long run_time_id, void * memory_start, u_long memory_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0072 — API `_pthread_ticktimer_create`
**Prototype (Reference Card)**
```c
int mpx _pthread_ticktimer_create(pthread_ticktimer_t *ticktimer_handle, pthread_ticktimerattr_t * attributes, void (*expiration_routine)(pthread_ticktimer_t *, void *), void *argument, tick_t initial_ticks, tick_t reload_ticks);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0073 — API `_pthread_ticktimerattr_destroy`
**Prototype (Reference Card)**
```c
int mpx _pthread_ticktimerattr_destroy(pthread_ticktimerattr_t *ticktimer_attributes);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0074 — API `_pthread_ticktimerattr_getcontroladdr`
**Prototype (Reference Card)**
```c
int mpx _pthread_ticktimerattr_getcontroladdr(pthread_ticktimerattr_t * ticktimer_attributes, void ** ticktimer_control_address);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0075 — API `_pthread_ticktimerattr_getcontrolsize`
**Prototype (Reference Card)**
```c
int mpx _pthread_ticktimerattr_getcontrolsize(pthread_ticktimerattr_t * ticktimer_attributes, size_t * ticktimer_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0076 — API `_pthread_ticktimerattr_getname`
**Prototype (Reference Card)**
```c
int mpx _pthread_ticktimerattr_getname(pthread_ticktimerattr_t * ticktimer_attributes, char ** name);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0077 — API `_pthread_ticktimerattr_setcontroladdr`
**Prototype (Reference Card)**
```c
int mpx _pthread_ticktimerattr_setcontroladdr(pthread_ticktimerattr_t * ticktimer_attributes, void * ticktimer_control_address, size_t ticktimer_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0078 — API `_pthread_ticktimerattr_setname`
**Prototype (Reference Card)**
```c
int mpx _pthread_ticktimerattr_setname(pthread_ticktimerattr_t * ticktimer_attributes, char * name);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0079 — API `_sem_extend_init`
**Prototype (Reference Card)**
```c
int mpx _sem_extend_init(sem_t * semaphore_handle, int pshared, unsigned int value, semattr_t * semaphore_attributes);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0080 — API `_semattr_getcontrolsize`
**Prototype (Reference Card)**
```c
int mpx _semattr_getcontrolsize(semattr_t *semaphore_attributes, size_t * semaphore_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0081 — API `_semattr_getname`
**Prototype (Reference Card)**
```c
int mpx _semattr_getname(semattr_t *semaphore_attributes, char ** semaphore_name);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0082 — API `_semattr_init`
**Prototype (Reference Card)**
```c
int mpx _semattr_init(semattr_t *semaphore_attributes);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0083 — API `_semattr_setcontroladdr`
**Prototype (Reference Card)**
```c
int mpx _semattr_setcontroladdr(semattr_t *semaphore_attributes, void * semaphore_control_address, size_t semaphore_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0084 — API `astqueue_timedreceive`
**Prototype (Reference Card)**
```c
int mpx_pthread_f astqueue_timedreceive(pthread_fastqueue_t * fastqueue_handle, u_long * message_destination, size_t message_size, tick_t timeout_ticks);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0085 — API `clock_getres`
**Prototype (Reference Card)**
```c
int clock_getres(clockid_t clock_id, struct mpx_timespec *resolution);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service returns the current time resolution in resolution, which is effectively the underlying ticktimer periodic interrupt frequency.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int clock_getres(clockid_t clock_id, struct timespec *resolution);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location of where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0086 — API `clock_gettime`
**Prototype (Reference Card)**
```c
int clock_gettime(clockid_t clock_id, struct mpx_timespec *current_time);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service returns the current time in the destination specified by

**User Manual prototype (informative)**
```c
#include <pthread.h>
int clock_gettime(clockid_t clock_id, struct timespec *current_time);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location of where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0087 — API `clock_settime`
**Prototype (Reference Card)**
```c
int clock_settime(clockid_t clock_id, struct mpx_timespec *new_time);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service sets the current time to the value specified by new_time.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int clock_settime(clockid_t clock_id, struct timespec *new_time);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location of where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0088 — API `d_memorypoolattr_getcontrolsize`
**Prototype (Reference Card)**
```c
int mpx_pthrea d_memorypoolattr_getcontrolsize(pthread_memorypoolattr_t * memorypool_attributes, size_t * memorypool_control_size);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0089 — API `erattr_init`
**Prototype (Reference Card)**
```c
int mpx_pthread_ticktim erattr_init(pthread_ticktimerattr_t *ticktimer_attributes);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0090 — API `laddr`
**Prototype (Reference Card)**
```c
int mpx_semattr_getcontro laddr(semattr_t *semaphore_attributes, void ** semaphore_control_address);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0091 — API `mpx_mq_extend_open_check_params`
**Prototype (Reference Card)**
```c
mqd_t mpx_mq_extend_open_check_params(const char * queue_name, int operation, mode_t mode, struct mq_attr * queue_attributes, mq_extendattr_t * extend_attributes);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0092 — API `mpx_mq_extendattr_destroy`
**Prototype (Reference Card)**
```c
int mpx_mq_extendattr_destroy(mq_extendattr_t * queue_attributes);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service destroys the previously created extended message queue attributes structure pointed to by queue_attributes. Once destroyed, the extended message queue attributes structure cannot be used again unless it is recreated.

**User Manual prototype (informative)**
```c
#include <mqueue.h>
int mpx_mq_extendattr_destroy(mq_extendattr_t * queue_attributes);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0093 — API `mpx_mq_extendattr_getcontroladdr`
**Prototype (Reference Card)**
```c
int mpx_mq_extendattr_getcontroladdr(mq_extendattr_t * queue_attributes, void ** queue_control_address);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service returns the previously supplied message queue control structure address.

**User Manual prototype (informative)**
```c
#include <mqueue.h>
int mpx_mq_extendattr_getcontroladdr(mq_extendattr_t* queue_attributes,
void ** queue_control_address);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0094 — API `mpx_mq_extendattr_getcontrolsize`
**Prototype (Reference Card)**
```c
int mpx_mq_extendattr_getcontrolsize(mq_extendattr_t * queue_attributes, size_t * queue_control_size);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service returns the size of the internal message queue control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_mq_extendattr_setcontroladdr API.

**User Manual prototype (informative)**
```c
#include <mqueue.h>
int mpx_mq_extendattr_getcontrolsize(mq_extendattr_t* queue_attributes,
size_t * queue_control_size);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0095 — API `mpx_mq_extendattr_getqueueaddr`
**Prototype (Reference Card)**
```c
int mpx_mq_extendattr_getqueueaddr(mq_extendattr_t * queue_attributes, void ** queue_memory_address);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service returns the previously supplied message queue memory address.

**User Manual prototype (informative)**
```c
#include <mqueue.h>
int mpx_mq_extendattr_getqueueaddr(mq_extendattr_t* queue_attributes,
void ** queue_memory_address);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0096 — API `mpx_mq_extendattr_getqueuesize`
**Prototype (Reference Card)**
```c
int mpx_mq_extendattr_getqueuesize(mq_extendattr_t * queue_attributes, size_t * queue_memory_size);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service returns the size of the previously supplied message queue memory.

**User Manual prototype (informative)**
```c
#include <mqueue.h>
int mpx_mq_extendattr_getqueuesize(mq_extendattr_t* queue_attributes,
size_t * queue_memory_size);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0097 — API `mpx_mq_extendattr_init`
**Prototype (Reference Card)**
```c
int mpx_mq_extendattr_init(mq_extendattr_t * queue_attributes);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service initializes the extended message queue attributes structure with default condition variable creation values. Note that the extended message queue attributes are used only by the mpx_mq_extend_open API.

**User Manual prototype (informative)**
```c
#include <mqueue.h>
int mpx_mq_extendattr_init(mq_extendattr_t * queue_attributes);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0098 — API `mpx_mq_extendattr_setcontroladdr`
**Prototype (Reference Card)**
```c
int mpx_mq_extendattr_setcontroladdr(mq_extendattr_t * queue_attributes, void * queue_control_address, size_t queue_control_size);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service enables the developer to provide the memory for the internal MPX RTOS message queue structure as specified by the address in the queue_control_address parameter. This memory will subsequently be used for the next message queue created with this attribute structure. The memory size required for the internal message queue control structure can be found via a call to the mpx_mq_extendattr_getcontrol_size service.

**User Manual prototype (informative)**
```c
#include <mqueue.h>
int mpx_mq_extendattr_setcontroladdr(mq_extendattr_t* queue_attributes,
void * queue_control_address, size_t queue_memory_size);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0099 — API `mpx_mq_extendattr_setqueueaddr`
**Prototype (Reference Card)**
```c
int mpx_mq_extendattr_setqueueaddr(mq_extendattr_t * queue_attributes, void * queue_memory_address, size_t queue_memory_size);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service sets the internal message queue memory address to the address specified by queue_memory_address. This address will subsequently be used to supply the memory for the internal message queue memory on the next queue created with this attribute structure.

**User Manual prototype (informative)**
```c
#include <mqueue.h>
int mpx_mq_extendattr_setqueueaddr(mq_extendattr_t* queue_attributes,
void * queue_memory_address, size_t queue_memory_size);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0100 — API `mpx_pthread_attr_getcontroladdr`
**Prototype (Reference Card)**
```c
int mpx_pthread_attr_getcontroladdr(pthread_a ttr_t * thread_attributes, void ** thread_control_address);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service returns the thread control structure address stored in the thread attributes structure. By default, this value is NULL unless specified by the application via a call to mpx_pthread_attr_setcontroladdr.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_attr_getcontroladdr(pthread_attr_t *attributes,
void ** thread_control_address);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0101 — API `mpx_pthread_condattr_getcontrolsize`
**Prototype (Reference Card)**
```c
int mpx_pthread_condattr_getcontrolsize(pthre ad_condattr_t * condition_var_attributes, size_t * condition_var_control_size);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service returns the size of the internal condition variable control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_pthread_condattr_setcontroladdr API.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_condattr_getcontrolsize(pthread_condattr_t
* condition_var_attributes,
size_t * condition_var_control_size);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0102 — API `mpx_pthread_event_flags_clear`
**Prototype (Reference Card)**
```c
int mpx_pthread_event_flags_clear(pthread_event_flags_t * event_flags_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service clears all event flags in the specified event flags group.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_event_flags_clear(pthread_event_flags_t *
event_flags_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption is possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0103 — API `mpx_pthread_fastqueue_create`
**Prototype (Reference Card)**
```c
int mpx_pthread_fastqueue_create(pthread_fastqueue_t *fastqueue_handle, pthread_fastqueueattr_t * fastqueue_attributes, size_t message_size, int max_messages);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service initializes (creates) a fastqueue with the optional fast queue attributes. If successful, the fastqueue handle is set up for further use by the application.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_fastqueue_create(pthread_fastqueue_t *fastqueue_handle, pthread_fastqueueattr_t * fast_queue_attributes,
size_t message_size, int max_messages);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (160 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0104 — API `mpx_pthread_fastqueueattr_getname`
**Prototype (Reference Card)**
```c
int mpx_pthread_fastqueueattr_getname(pthread_fastqueue attr_t * fastqueue_attributes, char ** fastqueue_name);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service returns the previously supplied fastqueue name.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_fastqueueattr_getname(pthread_fastqueueattr_t
* fastqueue_attributes, char ** fastqueue_name);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0105 — API `mpx_pthread_memory_manager_enable`
**Prototype (Reference Card)**
```c
int mpx_pthread_memory_manager_enable(void);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service enables full management of the remaining memory supplied by the application when the MPX RTOS is started via mpx_pthread_start. The memory allocated with all subsequent system object creation and destruction will be fully managed.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_memory_manager_enable(void);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. This service does not result in preemption.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (242 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0106 — API `mpx_pthread_memorypool_free`
**Prototype (Reference Card)**
```c
int mpx_pthread_memorypool_free(void * allocated_memory);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service releases the previously allocated memory back to the memory pool it was allocated from. Any threads that are suspended on the memory pool that are waiting for this memory are resumed.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_memorypool_free(void * memory_to_release);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption occurs if no other threads are waiting for memory from the associated memory pool.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (232 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0107 — API `mpx_pthread_memorypoolattr_setname`
**Prototype (Reference Card)**
```c
int mpx_pthread_memorypoolattr_setname(p thread_memorypoolattr_t * memorypool_attributes, char * name);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service sets the memory pool name in the specified attribute structure.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_memorypoolattr_setname(pthread_memorypoolattr_t
* memorypool_attributes, char * memorypool_name);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0108 — API `mpx_pthread_mutexattr_getcontrolsize`
**Prototype (Reference Card)**
```c
int mpx_pthread_mutexattr_getcontrolsize(pthread_mutex attr_t * mutex_attributes, size_t * mutex_control_size);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service returns the size of the internal mutex control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_pthread_mutexattr_setcontroladdr API.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_mutexattr_getcontrolsize(pthread_mutexattr_t
*mutex_attributes, size_t * mutex_control_size);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0109 — API `mpx_pthread_partitionpool_allocate`
**Prototype (Reference Card)**
```c
int mpx_pthread_partitionpool_allocate(pthread_partitionpool_t * partitionpool_handle, void ** allocated_memory, size_t request_size);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service attempts to allocate a memory partition from the specified partition memory pool. If there is no partition memory in the pool, the calling thread is suspended until the request can be satisfied.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_partitionpool_allocate(pthread_partitionpool_t *
partitionpool_handle, void ** allocated_memory, size_t request_size);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. If the requested partition memory is available, no preemption takes place.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (100 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0110 — API `mpx_pthread_partitionpool_free`
**Prototype (Reference Card)**
```c
int mpx_pthread_partitionpool_free(void * allocated_memory);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service releases the previously allocated partition memory back to the partition memory pool it was allocated from. If a thread is suspended on this partition memory pool, the memory partition is given to the suspended thread, and it is resumed.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_partitionpool_free(void * memory_to_release);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption occurs if no other threads are waiting for partition memory from the associated partition memory pool.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (112 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0111 — API `mpx_pthread_resume`
**Prototype (Reference Card)**
```c
int mpx_pthread_resume(pthread_t thread_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthread+ service resumes a previously suspended thread. If the specified thread is not suspended, an error is returned.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_resume(pthread_t thread_handle);
```
**Callable from (normative extract)**
- This service is callable from the thread context and interrupt handlers (ISRs).

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption if the thread resumed is not a higher priority.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (80 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0112 — API `mpx_pthread_suspend`
**Prototype (Reference Card)**
```c
int mpx_pthread_suspend(pthread_t thread_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthread+ service suspends the specified thread. If the specified thread is already suspended, an error is returned.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_suspend(pthread_t thread_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. If the thread suspended is not the executing thread, there is no preemption.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (60 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0113 — API `mpx_pthread_tick_sleep`
**Prototype (Reference Card)**
```c
int mpx_pthread_tick_sleep(tick_t ticks_to_sleep);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service suspends the calling thread for the number of timer ticks specified by ticks_to_sleep. If a value of 0 ticks is supplied, this service returns immediately, i.e., the calling thread is not suspended.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_tick_sleep(tick_t ticks_to_sleep);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. If the number of ticks to sleep is zero, no preemption occurs.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (60 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0114 — API `mpx_pthread_ticks_get`
**Prototype (Reference Card)**
```c
tick_t mpx_pthread_ticks_get(void);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service returns the internal tick count, representing the number of timer interrupts.

**User Manual prototype (informative)**
```c
#include <pthread.h>
tick_t mpx_pthread_ticks_get(void);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption takes place as a result of this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (8 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0115 — API `mpx_pthread_ticktimer_destroy`
**Prototype (Reference Card)**
```c
int mpx_pthread_ticktimer_destroy(pthread_ticktimer_t *ticktimer_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service destroys a previously created but stopped ticktimer.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_ticktimer_destroy(pthread_ticktimer_t
*ticktimer_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (56 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0116 — API `mpx_pthread_ticktimer_start`
**Prototype (Reference Card)**
```c
int mpx_pthread_ticktimer_start(pthread_ticktimer_t *ticktimer_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service starts a previously created ticktimer.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_ticktimer_start(pthread_ticktimer_t *ticktimer_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (48 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0117 — API `mpx_pthread_ticktimer_stop`
**Prototype (Reference Card)**
```c
int mpx_pthread_ticktimer_stop(pthread_ticktimer_t *ticktimer_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service stops a previously created ticktimer. When stopped, the remaining number of ticks before expiration is saved. If the ticktimer is restarted, it is restarted with the previous remaining number of ticks.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_ticktimer_stop(pthread_ticktimer_t *ticktimer_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (48 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0118 — API `mpx_pthread_ticktimer_update`
**Prototype (Reference Card)**
```c
int mpx_pthread_ticktimer_update(pthread_ticktimer_t *ticktimer_handle , tick_t initial_ticks, tick_t reload_ticks);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service updates the initial ticks and reload ticks of a previously created but stopped ticktimer.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int mpx_pthread_ticktimer_update(pthread_ticktimer_t *ticktimer_handle,
tick_t initial_ticks, tick_t reload_ticks);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0119 — API `mpx_sem_timedwait`
**Prototype (Reference Card)**
```c
int mpx_sem_timedwait(sem_t * semaphore_handle, tick_t timeout_ticks);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0120 — API `mpx_semattr_destroy`
**Prototype (Reference Card)**
```c
int mpx_semattr_destroy(semattr_t *semaphore_attributes);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service destroys the previously created semaphore attributes structure pointed to by semaphore_attributes. Once destroyed, the semaphore attributes structure cannot be used again unless recreated.

**User Manual prototype (informative)**
```c
#include <semaphore.h>
int mpx_semattr_destroy(semttr_t * semaphore_attributes);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0121 — API `mpx_semattr_setname`
**Prototype (Reference Card)**
```c
int mpx_semattr_setname(semattr_t *semaphore_attributes, char * semaphor e_name);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This pthreadsmore service sets the semaphore name in the specified attribute structure.

**User Manual prototype (informative)**
```c
#include <semaphore.h>
int mpx_semattr_setname(semattr_t * semaphore_attributes,
char * semaphore_name);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0122 — API `mq_close`
**Prototype (Reference Card)**
```c
int mq_close(mqd_t message_queue);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service closes and destroys the specified message queue. An error is returned if any threads are suspended on the message queue.

**User Manual prototype (informative)**
```c
#include <mqueue.h>
int mq_close(mqd_t message_queue);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (72 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0123 — API `mq_getattr`
**Prototype (Reference Card)**
```c
int mq_getattr(mqd_t message_queue, struct mq_attr * queue_attributes);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service retrieves the current attributes of the specified message queue.

**User Manual prototype (informative)**
```c
#include <mqueue.h>
int mq_getattr(mqd_t message_queue, struct mq_attr* queue_attributes);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (48 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0124 — API `mq_open`
**Prototype (Reference Card)**
```c
mqd_t mq_open(const char * queue_name, int operation, mode_t mode, struct mq_attr * queue_attributes);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- If successful, this service opens (creates) the message queue specified and returns the message queue handle.

**User Manual prototype (informative)**
```c
#include <mqueue.h>
mqd_t mq_open(const char * queue_name, int operation, mode_t mode,
mq_attr * queue_attributes);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (176 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0125 — API `mq_receive`
**Prototype (Reference Card)**
```c
ssize_t mq_receive(mqd_t message_queue, char * message, size_t message_size, unsigned int *message_priority);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service receives the oldest message with the highest priority from the specified message queue. If the queue is empty and the O_NONBLOCK attribute is not set, the calling thread will suspend waiting for a message to arrive. If multiple threads are waiting on an empty queue, the first thread waiting is given the message.

**User Manual prototype (informative)**
```c
#include <mqueue.h>
int mq_receive(mqd_t message_queue, char * message,
size_t message_size, unsigned int * message_priority);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption is possible with this service if a message is in the message queue.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (184 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0126 — API `mq_send`
**Prototype (Reference Card)**
```c
int mq_send(mqd_t message_queue, const char * message, size_t message_size, unsigned int message_priority);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service sends the message to the specified message queue. If the queue is full and the O_NONBLOCK attribute is not set, the calling thread will suspend waiting for room in the queue.

**User Manual prototype (informative)**
```c
#include <mqueue.h>
int mq_send(mqd_t message_queue, char * message,
size_t message_size, unsigned int message_priority);
```
**Callable from (normative extract)**
- This service is callable only from the thread context and interrupt handlers (ISRs).
- If suspension is possible, the developer must not call this API from an interrupt handler. An easy way to ensure the queue attribute O_NONBLOCK is in force. Otherwise, unpredictable behavior is possible.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption is possible with this service if there is room in the message queue.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (168 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0127 — API `mq_setattr`
**Prototype (Reference Card)**
```c
int mq_setattr(mqd_t message_queue, const struct mq_attr * queue_attributes, struct mq_attr * previous_attributes);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service sets the attributes of the specified message queue. If the previous_attributes pointer is non-NULL, the attributes prior to this service are returned.

**User Manual prototype (informative)**
```c
#include <mqueue.h>
int mq_setattr(mqd_t message_queue, struct mq_attr * new_attributes,
struct mq_attr * previous_attributes);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (48 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0128 — API `mq_timedreceive`
**Prototype (Reference Card)**
```c
ssize_t mq_timedreceive(mqd_t message_queue, char * message, size_t message_size, unsigned int * message_priority, const struct mpx _timespec *absolute_timeout);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service receives the highest priority message from the specified message queue. If the queue is empty and the O_NONBLOCK attribute is not set, the calling thread will suspend waiting for a message to arrive. If the timeout is exceeded before a message arrives, the thread is resumed with an error.

**User Manual prototype (informative)**
```c
#include <pthread.h> #include <mqueue.h>
int mq_timedreceive(mqd_t message_queue, char * message,
size_t message_size, unsigned int * message_priority, const struct timespec absolute_timeout);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption is possible with this service if a message is in the message queue.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (208 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0129 — API `mq_timedsend`
**Prototype (Reference Card)**
```c
int mq_timedsend(mqd_t message_queue, const char * message, size_t message_size, unsigned int message_priority, const struct mpx _timespec *absolute_timeout);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service sends the message to the specified message queue. If the queue is full and the O_NONBLOCK attribute is not set, the calling thread will suspend waiting for room in the queue. If the timeout is exceeded before room for the message is available in the queue, the thread is resumed with an error.

**User Manual prototype (informative)**
```c
#include <mqueue.h>
int mq_timedsend(mqd_t message_queue, char * message,
size_t message_size, unsigned int message_priority, const struct timespec absolute_timeout);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption is possible with this service if there is room in the message queue.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (192 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0130 — API `nanosleep`
**Prototype (Reference Card)**
```c
int nanosleep(const struct mpx_timespec *request_time, struct mpx_timespec *remaining_time);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service causes the calling thread to suspend for the time specified in request_time. If an unmasked signal is sent to the thread while sleeping, the thread is resumed, and the remaining time is returned in remaining_time.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int nanosleep(struct timespec *request_time,
struct timespec *remainng_time);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (100 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0131 — API `ontroladdr`
**Prototype (Reference Card)**
```c
int mpx_pthread_event_flagsattr_getc ontroladdr(pthread_event_flagsattr_t * event_flags_attributes, void ** event_flags_control_address);
```
**Normative semantics source:** Reference Card surface only (no User Manual definition available in provided files)

**Verification:** Behavioral equivalence vs MPX (black-box), plus unit/integration tests.

### REQ-API-0132 — API `pthread_attr_getdetachstate`
**Prototype (Reference Card)**
```c
int pthread_attr_getdetachstate(pthread_attr_t * thread_attributes, int * detach_state);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service returns the detach state stored in the thread attributes structure. Valid detach states are PTHREAD_CREATE_JOINABLE (default) and PTHREAD_CREATE_DETACHED.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_attr_getdetachstate(pthread_attr_t *attributes,
int * detach_state);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0133 — API `pthread_attr_getstackaddr`
**Prototype (Reference Card)**
```c
int pthread_attr_getstackaddr(pthread_attr_t * thread_attributes, void ** stack_address);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service returns the stack address stored in the thread attributes structure. By default, this value is NULL unless specified by the application via a call to pthread_attr_setstackaddr.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_attr_getstackaddr(pthread_attr_t *attributes,
void ** stack_address);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0134 — API `pthread_attr_getstacksize`
**Prototype (Reference Card)**
```c
int pthread_attr_getstacksize(pthread_attr_t * thread_attributes, size_t * stack_size);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service returns the current stack size stored in the thread attributes structure. By default, this value is MPX_DEFAULT_STACK_SIZE unless specified by the application via a call to pthread_attr_setstacksize.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_attr_getstacksize(pthread_attr_t *attributes,
size_t *	stack_size);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0135 — API `pthread_attr_init`
**Prototype (Reference Card)**
```c
int pthread_attr_init(pthread_attr_t * thread_attributes);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service initializes the attributes structure with default thread creation values. These defaults are as follows:

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_attr_init(pthread_attr_t *attributes);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0136 — API `pthread_attr_setdetachstate`
**Prototype (Reference Card)**
```c
int pthread_attr_setdetachstate(pthread_attr_t * thread_attributes, int detach_state);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service sets the detach state specified by new_detach_state in the thread attributes structure. Valid detach states are PTHREAD_CREATE_JOINABLE and PTHREAD_CREATE_DETACHED.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_attr_setdetachstate(pthread_attr_t *attributes,
int	new_detach_state);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0137 — API `pthread_attr_setstackaddr`
**Prototype (Reference Card)**
```c
int pthread_attr_setstackaddr(pthread_attr_t * thread_attributes, void * stack_address);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service sets the stack address to the value specified by stack_address. The stack address must be at least PTHREAD_STACK_MIN number of bytes.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_attr_setstackaddr(pthread_attr_t *attributes,
void *	stack_address);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0138 — API `pthread_attr_setstacksize`
**Prototype (Reference Card)**
```c
int pthread_attr_setstacksize(pthread_attr_t * thread_attributes, size_t stack_size);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service sets the specified stack size in the thread attributes structure. The stack address must be at least PTHREAD_STACK_MIN number of bytes.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_attr_setstacksize(pthread_attr_t *attributes,
size_t	stack_size);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0139 — API `pthread_cancel`
**Prototype (Reference Card)**
```c
int pthread_cancel(pthread_t thread_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service cancels the specified thread. If the specified thread has cancellation disabled or deferred, this service marks the thread for cancellation at a later point determined by the thread itself. Otherwise, if the specified thread has asynchronous cancellation enabled, it is immediately canceled (terminated) by this service.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_cancel(pthread_t thread_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption takes place as a result of this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (112 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0140 — API `pthread_cleanup_pop`
**Prototype (Reference Card)**
```c
void pthread_cleanup_pop(int execute);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service pops the most recently pushed cleanup handler from the thread’s cleanup handler stack. If the specified execute parameter is non-zero and the cleanup handler function pointer is non-NULL, the cleanup handler is executed before returning to the caller.

**User Manual prototype (informative)**
```c
#include <pthread.h>
void pthread_cleanup_pop(int execute);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption takes place as a result of this service.

**Stack usage estimate (normative extract)**
- context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0141 — API `pthread_cleanup_push`
**Prototype (Reference Card)**
```c
void pthread_cleanup_push(void (*cleanup_handler)(void *), void * argument);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service pushes the specified cleanup_handler on the calling thread’s cleanup handler stack.

**User Manual prototype (informative)**
```c
#include <pthread.h>
void pthread_cleanup_push(void (*cleanup_handler)(void *),
void *argument);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption takes place as a result of this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (8 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0142 — API `pthread_cond_broadcast`
**Prototype (Reference Card)**
```c
int pthread_cond_broadcast(pthread_cond_t * condition_var_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service resumes all threads currently waiting on this condition variable.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_cond_broadcast(pthread_cond_t * condition_var_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption occurs if no other threads are waiting for the condition variable.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (96 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0143 — API `pthread_cond_destroy`
**Prototype (Reference Card)**
```c
int pthread_cond_destroy(pthread_cond_t * condition_var_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service destroys the previously created condition variable specified by condition_var_handle. If the condition variable is still in use by another thread, an error is returned.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_cond_destroy(pthread_cond_t * condition_var_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (56 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0144 — API `pthread_cond_init`
**Prototype (Reference Card)**
```c
int pthread_cond_init(pthread_cond_t * condition_var_handle, pthread_condattr_t * condition_var_attributes);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service initializes (creates) a condition variable with the optional condition variable attributes. If successful, the condition variable handle is set up for further use by the application.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_cond_init(pthread_cond_t * condition_var_handle,
pthread_condattr_t * condition_var_attributes);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (120 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0145 — API `pthread_cond_signal`
**Prototype (Reference Card)**
```c
int pthread_cond_signal(pthread_cond_t * condition_var_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service resumes the highest priority thread currently waiting on this condition variable.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_cond_signal(pthread_cond_t * condition_var_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption occurs if no other threads are waiting for the condition variable.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (112 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0146 — API `pthread_cond_timedwait`
**Prototype (Reference Card)**
```c
int pthread_cond_timedwait(pthread_cond_t * condition_var_handle, pthread_mutex_t * mutex_handle, const struct mpx_timespec *absolute_time);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service suspends on the condition variable specified by the condition_var_handle parameter. Before this service is called, the thread must have obtained the mutex specified by mutex_handle. Internally, MPX releases the mutex atomically with the thread suspension. Once the calling thread is resumed via a signal or broadcast to the condition variable, the mutex is reobtained before this service returns to the caller.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_cond_timedwait(pthread_cond_t * condition_var_handle,
pthread_mutex_t * mutex_handle,
const struct timespec *absolute_time);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (256 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0147 — API `pthread_cond_wait`
**Prototype (Reference Card)**
```c
int pthread_cond_wait(pthread_cond_t * condition_var_handle, pthread_mutex_t * mutex_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service suspends on the condition variable specified by the condition_var_handle parameter. Before this service is called, the thread must have obtained the mutex specified by mutex_handle. Internally, MPX releases the mutex atomically with the thread suspension. Once the calling thread is resumed via a signal or broadcast to the condition variable, the mutex is reobtained before this service returns to the caller.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_cond_wait(pthread_cond_t * condition_var_handle,
pthread_mutex_t * mutex_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (232 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0148 — API `pthread_condattr_destroy`
**Prototype (Reference Card)**
```c
int pthread_condattr_destroy(pthread_condattr_t * condition_var_attributes);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service destroys the previously created condition variable attributes structure pointed to by condition_var_attributes. Once destroyed, the condition variable attributes structure cannot be used again unless it is recreated.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_condattr_destroy(pthread_condattr_t *
condition_var_attributes);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0149 — API `pthread_condattr_getpshared`
**Prototype (Reference Card)**
```c
int pthread_condattr_getpshared(pthread_condattr_t * condition_var_attributes, int * process_sharing_designation);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service returns the current process sharing designation in the condition variable attribute structure. By default, the process sharing designation is PTHREAD_PROCESS_PRIVATE.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_condattr_getpshared(pthread_condattr_t * condition_var_attributes, int * process_sharing_designation);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0150 — API `pthread_condattr_init`
**Prototype (Reference Card)**
```c
int pthread_condattr_init(pthread_condattr_t * condition_var_attributes);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service initializes the condition variable attributes structure with default condition variable creation values. These defaults are as follows:

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_condattr_init(pthread_condattr_t *
condition_var_attributes);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0151 — API `pthread_condattr_setpshared`
**Prototype (Reference Card)**
```c
int pthread_condattr_setpshared(pthread_condattr_t * condition_var_attributes, int process_sharing_designation);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service sets the process sharing designation in the condition variable attribute structure to either PTHREAD_PROCESS_PRIVATE or PTHREAD_PROCESS_SHARED. By default, the process sharing designation is PTHREAD_PROCESS_PRIVATE.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_condattr_setpshared(pthread_condattr_t * condition_var_attributes, int	process_sharing_designation);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0152 — API `pthread_create`
**Prototype (Reference Card)**
```c
int pthread_create(pthread_t * thread_handle, pthread_attr_t * attr, void *(*start_routine)(void *), void *arg);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service creates a new thread that starts execution at the caller’s start_routine, passing verbatim the supplied arguments parameter. Note that the optional attributes parameter can specify additional attributes for the thread, including explicitly setting its priority, stack location, stack size, etc.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_create(pthread_t * thread_handle,
const pthread_attr * attributes, void * (*start_routine)(void *), void *arguments);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption if the newly created thread has the same or less priority than the calling thread. This service returns immediately after the creation of the new thread.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (192 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0153 — API `pthread_detach`
**Prototype (Reference Card)**
```c
int pthread_detach(pthread_t thread_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service places the specified thread in a detached state, such that it can’t be joined in the future. It is equivalent to creating the thread with the PTHREAD_CREATE_DETACHED attribute. When the specified, detached thread exits or returns, all of its resources are immediately released.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_detach(pthread_t thread_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0154 — API `pthread_equal`
**Prototype (Reference Card)**
```c
int pthread_equal(pthread_t first_thread, pthread_t second_thread);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service compares two thread handles. If the handles are the same, a non- zero value is returned. If they are not the same, a value of zero is returned.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_equal(pthread_t first_thread, pthread_t second_thread);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (8 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0155 — API `pthread_exit`
**Prototype (Reference Card)**
```c
void pthread_exit(void * exit_value);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service terminates the currently executing thread. If this thread is detached, all of the thread’s resources are released. Any cancellation cleanup handlers are popped and executed. The exit_value passed to this API will be sent to a thread that has joined this thread via the pthread_join API, assuming the value was requested in the join request (non-NULL destination value).

**User Manual prototype (informative)**
```c
#include <pthread.h>
void pthread_exit(void *exit_value);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- PREEMPTION. If a higher-priority thread has joined this thread, the exit processing will resume its execution, and preemption will occur.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (80 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0156 — API `pthread_join`
**Prototype (Reference Card)**
```c
int pthread_join(pthread_t thread_handle, void ** value_destination);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service suspends the currently running thread until the specified thread completes its processing. When the specified thread exits, the value supplied in its exit call is returned in the destination specified by the caller–if a non- NULL exit value destination pointer is provided.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_join(pthread_t thread_to_join, void ** value_destination);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (100 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0157 — API `pthread_mutex_destroy`
**Prototype (Reference Card)**
```c
int pthread_mutex_destroy(pthread_mutex_t * mutex_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service destroys the previously created mutex specified by mutex_handle. If a thread still owns the mutex, an error is returned.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_mutex_destroy(pthread_mutex_t * mutex_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (80 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0158 — API `pthread_mutex_init`
**Prototype (Reference Card)**
```c
int pthread_mutex_init(pthread_mutex_t * mutex_handle, pthread_mutexattr_t * mutex_attributes);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service initializes (creates) a mutex with the optional mutex attributes. If successful, the mutex handle is set up for further use by the application.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_mutex_init(pthread_mutex_t * mutex_handle,
pthread_mutexattr_t * mutex_attributes);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (120 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0159 — API `pthread_mutex_lock`
**Prototype (Reference Card)**
```c
int pthread_mutex_lock(pthread_mutex_t * mutex_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service assigns ownership to the calling thread if the mutex is available. Otherwise, if another thread already owns the mutex, the calling thread suspends until the other thread releases the mutex.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_mutex_lock(pthread_mutex_t * mutex_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption occurs if the mutex is available and ownership is assigned to the calling thread.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (136 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0160 — API `pthread_mutex_trylock`
**Prototype (Reference Card)**
```c
int pthread_mutex_trylock(pthread_mutex_t * mutex_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service assigns ownership to the calling thread if the mutex is available. Otherwise, if another thread already owns the mutex, this service immediately returns an error, i.e., there is no thread suspension like the pthread_mutex_lock service.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_mutex_trylock(pthread_mutex_t * mutex_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption occurs if the mutex is available and ownership is assigned to the calling thread.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0161 — API `pthread_mutex_unlock`
**Prototype (Reference Card)**
```c
int pthread_mutex_unlock(pthread_mutex_t * mutex_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service releases a previously owned mutex. If other threads are suspended waiting for the mutex, the first thread is given ownership and resumed.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_mutex_unlock(pthread_mutex_t * mutex_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. If no other threads are waiting for the mutex, no preemption occurs.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (168 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0162 — API `pthread_mutexattr_destroy`
**Prototype (Reference Card)**
```c
int pthread_mutexattr_destroy(pthread_mutexattr_t * mutex_attributes);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service destroys the previously created mutex attributes structure pointed to by mutex_attributes. Once destroyed, the mutex attributes structure cannot be used again unless it is recreated.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_mutexattr_destroy(pthread_mutexattr_t * mutex_attributes);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0163 — API `pthread_mutexattr_getprotocol`
**Prototype (Reference Card)**
```c
int pthread_mutexattr_getprotocol(pthread_mutexattr_t * mutex_attributes, int * protocol);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service returns the previously supplied mutex protocol. By default, the process sharing designation is PTHREAD_PRIO_NONE.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_mutexattr_getprotocol(pthread_mutexattr_t
*mutex_attributes, int * protocol);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0164 — API `pthread_mutexattr_getpshared`
**Prototype (Reference Card)**
```c
int pthread_mutexattr_getpshared(pthread_mutexattr_t * mutex_attributes, int * process_sharing_designation);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service returns the current process sharing designation in the mutex attribute structure. By default, the process sharing designation is PTHREAD_PROCESS_PRIVATE.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_mutexattr_getpshared(pthread_mutexattr_t *mutex_attributes,
int * process_sharing_designation);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0165 — API `pthread_mutexattr_gettype`
**Prototype (Reference Card)**
```c
int pthread_mutexattr_gettype(pthread_mutexattr_t * mutex_attributes, int * type);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service returns the previously supplied mutex type. By default, the mutex type designation is PTHREAD_MUTEX_ERRORCHECK.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_mutexattr_gettype(pthread_mutexattr_t
*mutex_attributes, int * type);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0166 — API `pthread_mutexattr_init`
**Prototype (Reference Card)**
```c
int pthread_mutexattr_init(pthread_mutexattr_t * mutex_attributes);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service initializes the mutex attributes structure with default mutex creation values. These defaults are as follows:

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_mutexattr_init(pthread_mutexattr_t *mutex_attributes);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0167 — API `pthread_mutexattr_setprotocol`
**Prototype (Reference Card)**
```c
int pthread_mutexattr_setprotocol(pthread_mutexattr_t * mutex_attributes, int protocol);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service sets the specified protocol in the previously created mutex attributes structure. By default, the protocol is PTHREAD_PRIO_NONE, which means priority inheritance is not enabled. Setting the protocol to PTHREAD_PRIO_INHERIT enables priority inheritance when a mutex is created with this attribute structure. Please see the mutex section in Chapter 6 for more information on priority inheritance.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_mutexattr_setprotocol(pthread_mutexattr_t
*mutex_attributes, int protocol);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0168 — API `pthread_mutexattr_setpshared`
**Prototype (Reference Card)**
```c
int pthread_mutexattr_setpshared(pthread_mutexattr_t * mutex_attributes, int process_sharing_designation);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service sets the process sharing designation in the mutex attribute structure to either PTHREAD_PROCESS_PRIVATE or PTHREAD_PROCESS_SHARED. By default, the process sharing designation is PTHREAD_PROCESS_PRIVATE.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_mutexattr_setpshared(pthread_mutexattr_t *mutex_attributes,
int	process_sharing_designation);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0169 — API `pthread_mutexattr_settype`
**Prototype (Reference Card)**
```c
int pthread_mutexattr_settype(pthread_mutexattr_t * mutex_attributes, int type);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service sets the specified mutex type in the previously created attributes structure. By default, the type is PTHREAD_MUTEX_ERRORCHECK.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_mutexattr_settype(pthread_mutexattr_t
* mutex_attributes, int type);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the context of the application.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0170 — API `pthread_self`
**Prototype (Reference Card)**
```c
pthread_t pthread_self(void);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service returns the thread handle of the currently running thread.

**User Manual prototype (informative)**
```c
#include <pthread.h> pthread_t pthread_self(void);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (8 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0171 — API `pthread_setcancelstate`
**Prototype (Reference Card)**
```c
int pthread_setcancelstate(int new_state, int * old_state);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service sets the calling thread’s cancel state as specified by new_state. If old_state is non-NULL, the previous cancel state is stored in the specified destination.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_setcancelstate(int new_state, int * old_state);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (120 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0172 — API `pthread_setcanceltype`
**Prototype (Reference Card)**
```c
int pthread_setcanceltype(int new_type, int * old_type);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service sets the calling thread’s cancel type as specified by new_type. If old_type is non-NULL, the previous cancel type is stored in the specified destination.

**User Manual prototype (informative)**
```c
#include <pthread.h>
int pthread_setcanceltype(int new_type, int * old_type);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, there should be at least (120 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0173 — API `pthread_testcancel`
**Prototype (Reference Card)**
```c
void pthread_testcancel(void);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service checks for a pending cancel request for the calling thread. If detected, the calling thread cancels itself via pthread_exit.

**User Manual prototype (informative)**
```c
#include <pthread.h>
void pthread_testcancel(void);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. If a cancel request is not pending for the calling thread, there is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (96 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0174 — API `sched_yield`
**Prototype (Reference Card)**
```c
int sched_yield(void);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service relinquishes control to the next thread of the same priority currently ready for execution. If there is no other thread of the same priority ready for execution, this service simply returns a successful status.

**User Manual prototype (informative)**
```c
#include <sched.h> int sched_yield(void);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. If no other threads of the same priority are ready for execution, this service returns without preemption.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (8 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0175 — API `sem_destroy`
**Prototype (Reference Card)**
```c
int sem_destroy(sem_t * semaphore_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service destroys the previously created semaphore specified by semaphore_handle. An error is returned if one or more threads are suspended on this semaphore.

**User Manual prototype (informative)**
```c
#include <semaphore.h>
int sem_destroy(sem_t * semaphore_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (64 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0176 — API `sem_init`
**Prototype (Reference Card)**
```c
int sem_init(sem_t * semaphore_handle, int pshared, unsigned int value);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service initializes (creates) a semaphore with the specified initial value. If successful, the semaphore handle is available for use by the application.

**User Manual prototype (informative)**
```c
#include <semaphore.h>
int sem_init(sem_t * semaphore_handle, int pshared,
unsigned int value);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. There is no preemption possible with this service.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (128 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0177 — API `sem_post`
**Prototype (Reference Card)**
```c
int sem_post(sem_t * semaphore_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service posts to the specified semaphore. If one or more threads are waiting, the highest priority thread waiting is resumed. Otherwise, if no threads are waiting, the internal semaphore count is incremented by one.

**User Manual prototype (informative)**
```c
#include <semaphore.h>
int sem_post(sem_t * semaphore_handle);
```
**Callable from (normative extract)**
- This service is callable from the thread context and interrupt handlers (ISRs).

**Real-time scenario (normative extract)**
- NO PREEMPTION. If no other threads are waiting for the semaphore, no preemption occurs.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (120 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0178 — API `sem_trywait`
**Prototype (Reference Card)**
```c
int sem_trywait(sem_t * semaphore_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- If the semaphore is available (count greater than zero), this service decrements the count and returns success. Otherwise, an error is returned.

**User Manual prototype (informative)**
```c
#include <semaphore.h>
int sem_trywait(sem_t * semaphore_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. No preemption occurs if the semaphore is available.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0179 — API `sem_wait`
**Prototype (Reference Card)**
```c
int sem_wait(sem_t * semaphore_handle);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- If the semaphore is available (count greater than zero), this service decrements the semaphore count by one and returns success to the caller. Otherwise, if the semaphore is zero, the calling thread suspends until the semaphore is available.

**User Manual prototype (informative)**
```c
#include <semaphore.h>
int sem_wait(sem_t * semaphore_handle);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Real-time scenario (normative extract)**
- NO PREEMPTION. If the semaphore is available, no preemption takes place.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (92 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0180 — API `sleep`
**Prototype (Reference Card)**
```c
u_int sleep(unsigned int seconds);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service causes the calling thread to suspend for the number of seconds specified in seconds. If an unmasked signal is sent to the thread while sleeping, the thread is resumed, and the remaining seconds are returned.

**User Manual prototype (informative)**
```c
#include <unistd.h>
unsigned int sleep(unsigned int seconds);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (132 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0181 — API `time`
**Prototype (Reference Card)**
```c
time_t time(mpx_time_t *return_seconds);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service returns the current number of seconds. If a non-null value for return_seconds is provided, the current number of seconds is also placed in the destination pointed to by return_seconds.

**User Manual prototype (informative)**
```c
#include <pthread.h>
time_t time(time_t * return_seconds);
```
**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

### REQ-API-0182 — API `usleep`
**Prototype (Reference Card)**
```c
int usleep(useconds_t microseconds);
```
**Normative semantics source:** User Manual (Chapter 7)

**Description (extract)**
- This service causes the calling thread to suspend for the time specified in microseconds. If an unmasked signal is sent to the thread while sleeping, the thread is resumed, and an error is returned.

**User Manual prototype (informative)**
```c
#include <unistd.h>
int usleep(useconds_t microseconds);
```
**Callable from (normative extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.

**Stack usage estimate (normative extract)**
- From the location where this API is called, at least (76 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

**Verification:** Unit/Integration test(s) and behavior comparison vs MPX; plus inspection for callable-context enforcement.

