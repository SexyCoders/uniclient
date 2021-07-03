import RichGridExample from './components/rich-grid-example/RichGridExample.vue';

import {createRouter, createWebHistory} from 'vue-router';

const router = createRouter({
    history: createWebHistory(),
    routes: [
        {path: '/', component: RichGridExample, name: 'Rich Grid with Pure JavaScript'},
    ],
})

export default router;
