<template>
  <CRow>
    <CCol :xs="12">
      <CCard class="mb-4">
        <CCardHeader>
          <strong>Customers</strong> 
        </CCardHeader>
        <CCardBody>
            <CTable color="dark" responsive>
              <CTableHead>
                <CTableRow >
                <CTableHeaderCell scope="col" v-for="header in Object.keys(this.$store.getters.getCurrentTableData[0])">
                  {{header}}
                </CTableHeaderCell>
                </CTableRow>
              </CTableHead>
              <CTableBody>
                <CTableRow active v-for="obj in this.$store.getters.getCurrentTableData">
                  <CTableDataCell v-for="field in obj">{{field}}</CTableDataCell>
                </CTableRow>
              </CTableBody>
            </CTable>
        </CCardBody>
      </CCard>
    </CCol>
  </CRow>
</template>

<script>
export default {
  name: 'MyTable',
}
</script>
