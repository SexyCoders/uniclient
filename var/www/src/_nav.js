export default [
  {
    component: 'CNavItem',
    name: 'Dashboard',
    to: '/dashboard',
    icon: 'cil-speedometer',
    badge: {
      color: 'primary',
      text: 'NEW',
    },
  },
  {
    component: 'CNavGroup',
    name: 'Customers',
    to: '/theme',
    //icon: 'cil-address-book',
    items: [
      {
        component: 'CNavItem',
        name: 'Info',
        to: '/customers',
        //icon: 'cil-clear-all',
      },
      {
        component: 'CNavItem',
        name: 'Manage',
        to: '/customers',
        //icon: 'cil-clear-all',
      },
    ]
  },
]
